#include<stdio.h>
typedef unsigned long int ULI;

ULI Factorial(int iNo)
{
    int iCnt = 0;
    ULI iFact = 1;

    for(iCnt = iNo; iCnt > 0; iCnt--)
    {
        iFact = iFact * iCnt;
    }
    return iFact;
}

int main()
{
    int iValue = 0;
    ULI iRet = 0;

    printf("Enter number : \n");
    scanf("%d",&iValue);

    iRet = Factorial(iValue);
    printf("Factorial is : %ld\n",iRet);

    return 0;
}c