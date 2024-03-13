#include<stdio.h>
#include<stdbool.h>

bool ChkPallindrom(int iNo)
{
    int iTemp = iNo;
    int iDigit = 0;
    int iReverse = 0;

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        iReverse = (iReverse*10) + iDigit;
        iNo = iNo / 10;
    }
    if(iTemp == iReverse)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int iValue = 0;
    bool bRet = false;

    printf("Enter number : ");
    scanf("%d",&iValue);

    bRet = ChkPallindrom(iValue);
    if(bRet == true)
    {
        printf("%d is pallindrom\n",iValue);
    }
    else
    {
        printf("%d is not pallindrom\n",iValue);
    }

    return 0;
}