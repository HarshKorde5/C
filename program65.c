#include<stdio.h>
int MinimumDigit(int iNo)
{
    int iDigit = 0;
    int iMin = 9;

    if(iNo < 0)
    {
        iNo = -iNo;
    }

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        if(iDigit < iMin)
        {
            iMin = iDigit;
        }
        iNo = iNo / 10;
    }
    return iMin;
}

int main()
{
    int iValue = 0;
    int iRet = 0;
    printf("Enter number : ");
    scanf("%d",&iValue);
    iRet = MinimumDigit(iValue);
    printf("Smallest number in %d is %d\n",iValue,iRet);
    return 0;
}