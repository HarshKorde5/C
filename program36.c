#include<stdio.h>
#include<stdbool.h>

typedef unsigned long int ULI;

ULI CalculatePower(int iBase,int iPower)
{
    ULI iResult = 1;
    int iCnt = 0;
    
    if((iBase < 0) || (iPower < 0))
    {
        return 0;
    }
    
    for(iCnt = 1;iCnt <= iPower;iCnt++)
    {
        iResult = iResult*iBase;
    }
    return iResult;
}

int main()
{
    int iValue1 = 0,iValue2 = 0;
    ULI iRet = 0;

    printf("Enter base : \n");
    scanf("%d",&iValue1);

    printf("Enter power : \n");
    scanf("%d",&iValue2);

    iRet = CalculatePower(iValue1,iValue2);

    printf("Result is %ld\n",iRet);
    return 0;
}