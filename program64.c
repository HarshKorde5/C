#include<stdio.h>

float DigitsAverage(int iNo)
{
    int iDigit = 0;
    int iSum = 0;
    int iCount = 0;

    if(iNo < 0)
    {
        iNo = -iNo;
    }

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        iCount++;
        iSum = iSum + iDigit;
        iNo = iNo / 10;
    }

    return ((float)iSum/(float)iCount);
}

int main()
{
    int iValue = 0;
    float fRet = 0.0f;

    printf("Enter number : ");
    scanf("%d",&iValue);

    fRet = DigitsAverage(iValue);
    printf("Average is %f\n",fRet);

    return 0;
}