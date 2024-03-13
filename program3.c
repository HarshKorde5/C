#include<stdio.h>
int main()
{
    int iValue1=0,iValue2=0,iAns=0;
    printf("Enter first number : ");
    scanf("%d",&iValue1);
    printf("Enter second number : ");
    scanf("%d",&iValue2);
    iAns = iValue1+iValue2;
    printf("Addition is : %d",iAns);
    return 0;
}