//Write a program which checks whether number is divisible by 3 and 5

#include<stdio.h>       //For printf and scanf
#include<stdbool.h>     //For bool datatype

//////////////////////////////////////////////////////////
//  Function name   :   CheckDivisible
//  I/P             :   Integer
//  O/P             :   Boolean
//  Description     :   Checks whether IP is divisible by 3 and 5
//  Author          :   Harsh Munjaji Korde
//  Date            :   25/04/2023
//////////////////////////////////////////////////////////

bool CheckDivisible(int iNo)
{
    if(((iNo % 5) == 0)&& ((iNo % 3) ==0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

////////////////////////////////////////////////////
//Entry point function
////////////////////////////////////////////////////

int main()
{
    int iValue = 0;                     //Variable to accept return value
    bool bRet = false;                  //Variable to accept return value
    printf("Please enter number to check whether it is even or odd : \n");
    scanf("%d",&iValue);

    bRet = CheckDivisible(iValue);        //Function cha call

    if((bRet == true))
    {
        printf("%d is Divisible by 3 and 5 both \n",iValue);
    }
    else
    {
        printf("%d is not Divisible by 3 and 5 both \n",iValue);
    }
    return 0;
}