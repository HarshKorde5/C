#include<stdio.h>

void Display(int iNo)
{
    int iCnt = 0;

    if(iNo < 0)     //Filter
    {
        printf("Please enter the positive number\n");
        return;
    }

    //      1          2       3
    for(iCnt = 1; iCnt <= iNo; iCnt++)    //4
    {
    printf("JAI GANESH...\n");
    }

}

int main()
{
    int iValue = 0;

    printf("Enter the frequency of Jai Ganesh statement : \n");
    scanf("%d",&iValue);

    Display(iValue);
    
    return 0;
}