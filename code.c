#include <stdio.h>
void choosing_course_assesment_method(float *x); // Choosing course assessment options function decleration called by refrence 
float standard_course_assessment(float *x); // Standard course assessment option function decleration called by refrence 
float quiz(float quiz_grade); // Quiz function decleration 
float mid_term(float mid_term_grade); // midterm function decleration 
float project(float a); // Projuct function decleration 
float participation(float a); // Participation function decleration 
float final(float a); // Final function decleration 
void pass_fail_options(void); // Choosing pass or fail option function decleration 
float option_a(float a); // Pass option function decleration 
float option_b(float a); // Fail option function decleration 
float letter_grade(float a);  // Printing the letter grade function decleration of the course using the total 
float calculate_grade_points(float x[], int len); // Exchange the total by grades point function decleration 
void calculate_gpa(float decision, int x, float y[], float c[], int m); // Calculate the GPA function decleration 
#define letter_course_grade 'a' // Character variable of Letter course grade defined globally 

int main()
{
    char option, letter; // character variables decleration
    float GPA, total, agreement, summation=0; // float variables decleration
    int course_assesment_method, pmu_id,course_credits, total_course_credits=0, course_num=0, len; // Integer variables decleration
    float grade_points[course_num]; // float array decleration of grade points
    float course_credits_array[course_num]; // float array decleration of course credits of each course
    float final_total[course_num]; // float array decleration of the final total gardes
    printf("Enter your PMU ID :"); 
    scanf("%d", &pmu_id); // saving PMU ID from the user in the pmu_id variable
    printf("How many course did you take this semester :");
    scanf("%d", &course_num); // saving course number from user in course_num variable
    for (int i=0; i<course_num; i++) // for loop to display the programme 
    {
        /* maximmum 4 hours and should be in the Standard assesment only 
        printf("How many credits points on this course?");
        scanf("%d",&course_credits); // saving course credits from user in course_credits variable
        */
        choosing_course_assesment_method(&total); // call course assessment options function by refrenced to total
        course_credits_array[i]=course_credits; // saving the course credit as an element in course credits array
        total_course_credits=total_course_credits+ course_credits; //calculating total course credits
        grade_points[i]=total; // saving the total as an element in grade points array
    }
    len= sizeof(grade_points[course_num])/sizeof(grade_points[0]); // calculate the length of grade points array 
    calculate_grade_points(grade_points, len); // call calculate_grade_points function
    printf("Do you want to calculate your GPA?\n enter 1 for yes \n enter 0 for no\n");
    scanf("%f", &agreement); //saving the choosing GPA option in agreement variable
    calculate_gpa(agreement, total_course_credits, course_credits_array, grade_points, course_num); // call calculate_gpa function

return 0;
    
}

void choosing_course_assesment_method(float *total) // choosing_course_assesment_method function definition 
{
    int course_assesment_method; // integer variables decleration
    float total_grades; // float variables decleration
    printf("Please choose your course assesment method you prefer: \n 1 for Standard Course Assessment \n 2 for Pass/Fail Evaluation Options\n");
    scanf("%d", &course_assesment_method); // saving decision from the user in the course_assesment_method variable
    if (course_assesment_method == 1) // if else-if statment to direct the programme 
    {
        standard_course_assessment(&total_grades); //call standard_course_assessment method function 
        
    }
    else if (course_assesment_method == 2) 
    {
        pass_fail_options(); //call pass_fail_options method function 
    }
    *total=total_grades; // updating the total variable
}

float standard_course_assessment(float *total_grades) // standard_course_assessment function definition 
{
    float quiz1,quiz_grade,midterm1,mid_term_grade,project1,project_grade,participation1,participation_grade,final1,final_grade, *p1; // float variables decleration
    quiz1 = quiz(quiz_grade); //call quiz function and saved in quiz variable
    midterm1 = mid_term(mid_term_grade); //call midterm function and saved in midterm variable
    project1 = project(project_grade); //call project function and saved in project variable
    participation1= participation(participation_grade); //call participation function and saved in participation variable
    final1= final(final_grade); //call final function and saved in final variable
    *total_grades=quiz1+midterm1+project1+participation1+final1; // point to total_grades and updating the value
    p1= &*total_grades; // point the pointer to the total_grades address
    letter_grade(*p1); //call letter_grade function 
}

float letter_grade(float a) // letter_grade function definition 
{
    char letter; // character variables decleration
    if(a>=95) // if and else-if statment to categorize the total grade 
    {
        letter='A';
        printf("your letter grade is A+ \n\n");
    }
    else if(a>=90)
    {
        letter='a';
        printf("your letter grade is A\n\n");
    }
    else if(a>=85)
    {
        letter='B';
        printf("your letter grade is B+\n\n");
    }
    else if(a>=80)
    {
        letter='b';
        printf("your letter grade is B\n\n");
    }
    else if(a>=75)
    {
        letter='C';
        printf("your letter grade is C+\n\n");
    }
    else if(a>=70)
    {
        letter='c';
        printf("your letter grade is C\n\n");
    }
    else if(a>=65)
    {
        letter='D';
        printf("your letter grade is D+\n\n");
    }
    else if(a>=60)
    {
        letter='d';
        printf("your letter grade is D\n\n");
    }
    else 
    {
        letter='F';
        printf("your letter grade is F\n\n");
    }
    
    letter==letter_course_grade; // equal letter variable with the letter_course_grade variable value
}

float quiz(float a) // quiz function definition 
{
    float quiz_grade; // float variables decleration
    printf("Enter your Quiz grade out of 15: ");
    scanf("%f", &quiz_grade);  // saving quize grade from the user in the quiz_grade variable
    if (quiz_grade > 15)
    {
        printf("please the grade should be less than 15 \n ");
        quiz(a); //call quiz function to reenter the grade 
    }
    else 
    {
      return quiz_grade; //returning the quiz grade 
    }
}

float mid_term(float a) // midterm function definition 
{
    float mid_term_grade; // float variables decleration
    printf("Enter your mid_term grade grade out of 30: ");
    scanf("%f", &mid_term_grade); // saving midterm grade from the user in the mid_term_grade variable
        if (mid_term_grade > 30)
        {
            printf("please the grade should be less than 30 \n ");
            mid_term(a); // call mid_term function to reenter the grade 
        }
        else 
        {
          return mid_term_grade; //returning the midterm grade 
        }
}

float project(float a) // project function definition 
{
    float project_grade; // float variables decleration
    printf("Enter your project grade grade out of 25: ");
    scanf("%f", &project_grade); // saving project grade from the user in the project_grade variable
        if (project_grade > 25)
        {
            printf("please the grade should be less than 25 \n ");
            project(a); // call project function to reenter the grade 
        }
        else 
        {
          return project_grade;  //returning the project grade 
        }
}

float participation(float a) // participation function definition 
{
    float participation_grade; // float variables decleration
    printf("Enter your participation grade grade out of 10: ");
    scanf("%f", &participation_grade); // saving participation grade from the user in the participation_grade variable
        if (participation_grade > 10)
        {
            printf("please the grade should be less than 10 \n ");
            participation(a);  // call project function to reenter the grade 
        }
        else 
        {
          return participation_grade; //returning the participation grade 
        }
}

float final(float a) // final function definition 
{
    float final_grade; // float variables decleration
    printf("Enter your final grade grade out of 20: ");
    scanf("%f", &final_grade); // saving final grade from the user in the final_grade variable
        if (final_grade > 20)
        {
            printf("please the grade should be less than 20 \n ");
            final(a); // call final function to reenter the grade 
        }
        else 
        {
          return final_grade; //returning the final grade 
        }
}

void pass_fail_options() // pass or fail options function definition 
{
    char option; // character variables decleration
    float a; // float variables decleration
    printf("Please enter the option you want: \n");
    scanf("%c", &option); // saving option from the user in the option variable
    switch (option) // switch statment to know the decision 
    {
        case 'A':
        case 'a':
            option_a(a); //call option_a function 
            break;
        case 'B':
        case 'b':
            option_b(a); // call option_b function
            break;
        default:
            printf("Please choose option A or B \n");
            pass_fail_options(); // call pass_fail_options function to reenter the correct option
            break;
    }
}
 
float option_a(float total) // option a function definition
{
    float quiz1,quiz_grade,midterm1 ,mid_term_grade,project1,project_grade,participation1,participation_grade; // float variables decleration
    quiz1 = quiz(quiz_grade); //call quiz function and saved in quiz variable
    midterm1 = mid_term(mid_term_grade); //call midterm function and saved in midterm variable
    project1 = project(project_grade); //call project function and saved in project variable
    participation1= participation(participation_grade); //call participation function and saved in participation variable
    total=quiz1+midterm1+project1+participation1; // calculate the total
    if (total>45) // if statment to check the student if they pass or did not pass
    {
        printf("Dear student your total in this course is %.2f \n",total);
        printf("Congrats you Pass this course\n");
    }
    else 
    {
        printf("Dear student your total is %.2f in this course\n", total);
        printf("Sorry to inform you that you failed passing this course\n");
    }
    return total;
}

float option_b(float total) // option b function definition
{
    float quiz1,quiz_grade,midterm1,mid_term_grade,project1,project_grade,participation1,participation_grade,final1,final_grade; // float variables decleration
    quiz1 = quiz(quiz_grade); //call quiz function and saved in quiz variable
    midterm1 = mid_term(mid_term_grade); //call midterm function and saved in midterm variable
    project1 = project(project_grade); //call project function and saved in project variable
    participation1= participation(participation_grade); //call participation function and saved in participation variable
    final1= final(final_grade); //call final function and saved in final variable
    total=quiz1+midterm1+project1+participation1+final1; // calculate the total
    if (total>65) // if statment to check the student if they pass or did not pass
    {
        printf("Dear student your total in this course is %.2f \n",total);
        printf("Congrats you Pass this course\n");
        
    }
    else 
    {
        printf("Dear student your total is %.2f in this course\n", total);
        printf("Sorry to inform you that you failed passing this course\n");
    }
    return total;
}

float calculate_grade_points(float x[], int len) // calculate the grade pronts function definition
{
    for(int i=0; i<=len; ++i) // to change the array elemnt from total of grades to grade points 
        {
            if (x[i]>90)
            {
                x[i]=4; // calculate grade points from the element which represent the total of A+ and A
            }
            else if (x[i]>80)
            {
                x[i]=3; // calculate grade points from the element which represent the total of B+ and B
            }
            else if (x[i]>70)
            {
                x[i]=2; // calculate grade points from the element which represent the total of C+ and C
            }
            else if (x[i]>60)
            {
                x[i]=1; // calculate grade points from the element which represent the total of D+ and D
            }
            else 
            {
                x[i]=0; // calculate grade points from the element which represent the total of F
            }
    }
}
void calculate_gpa(float decision, int totoal_credits, float credits_array[], float grade_points_array[], int course_number)
{
    float final_total[course_number], summation=0, GPA; // float variables decleration
    if (decision==1) //else if statment to know the decision of calculating gpa
    {
        for(int i=0; i<=course_number; i++) // calculate the multiplication of two array and add all the values
            {
                final_total[i]=grade_points_array[i]*credits_array[i]; //calculate the total multiplication of grade_points_array by credits_array
                summation=final_total[i]+ summation; // calculate the total array
            }
        GPA= (summation/totoal_credits); // calculating the GPA formula 
        printf("Your GPA for this course is %.2f", GPA);
    }
    else if (decision!=0)
    {
        printf("sorry you have enterd wrong number please try again");
    }

}






