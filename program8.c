//Write a program which accepts the marks and display the class accordinly
//0 to 34   Fail
//35 to 49  Pass Class
//50 to 59  Second class
//60 to 74  First Class  
//75 to 100 First Class with distinciton

#include<stdio.h>       //For printf and scanf
#include<stdbool.h>     //For bool datatype

void DisplayClass(float fMarks)
{
    if((fMarks < 0.0f) || (fMarks > 100.00f))   //filter
    {
        printf("Invalid input\n");
        printf("Please enter valid percentage\n");
        return;
    }

    if((fMarks >= 0.0f)&&(fMarks < 35.00f))
    {
        printf("Your are fail\n");
    }
    else if((fMarks >= 35.00f)&&(fMarks < 50.00f))
    {
        printf("You got Pass Class\n");
    }
    else if((fMarks >= 50.00f)&&(fMarks < 60.00f))
    {
        printf("You got Second Class\n");
    }
    else if((fMarks >= 60.00f)&&(fMarks < 75.00f))
    {
        printf("You got First Class\n");
    }
    else if((fMarks >= 75.00f)&&(fMarks < 100.00f))
    {
        printf("You got First Class with Distinction\n");
    }

}

int main()
{
    float fValue = 0.0f;

    printf("Please enter your percentage : \n");
    scanf("%f",&fValue);

    DisplayClass(fValue);

    return 0;
}