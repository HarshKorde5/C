#include<stdio.h>

void Display(int iNo)
{
    if(iNo < 0)     //updater
    {
        iNo = -iNo;
    }

    int iCnt = 0;

    for(iCnt = 1; iCnt <= iNo; iCnt++)
    {
        printf("%d\n",iCnt);
    }

}
int main()
{
    int iValue = 0;

    printf("Enter the number to print : \n");
    scanf("%d",&iValue);

    Display(iValue);
    
    return 0;
}