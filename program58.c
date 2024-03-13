#include<stdio.h>
#include<stdbool.h>

int CountDigitFrequency(int iNo1,int iNo2)
{
    int iCount = 0;

    if((iNo2 < 0) || (iNo2 >9))
    {
        printf("Enter the digit in range 0 to 9 \n");
        return iCount;
    }
    if(iNo1 < 0)
    {
        iNo1 = -iNo1;
    }
    
    int iDigit = 0;
    while(iNo1 != 0)
    {
        iDigit = iNo1%10;
        if(iDigit == iNo2)
        {
            iCount++;
        }
        iNo1 = iNo1/10;
    }
    return iCount;
}

int main()
{
    int iValue1 = 0,iValue2 = 0;
    int iRet = 0;
    printf("Enter number : ");
    scanf("%d",&iValue1);
    printf("Enter digit (0 to 9): ");
    scanf("%d",&iValue2);
    iRet = CountDigitFrequency(iValue1,iValue2);
    printf("Frequency of %d in %d is %d\n",iValue2,iValue1,iRet);

    return 0;
}