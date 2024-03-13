#include<stdio.h>
#include<stdbool.h>

bool ChkDigit(int iNo1,int iNo2)
{
    bool bFlag = false;

    if((iNo2 < 0) || (iNo2 >9))
    {
        printf("Enter the digit in range 0 to 9 \n");
        return bFlag;
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
            bFlag = true;
            break;
        }
        iNo1 = iNo1/10;
    }
    return bFlag;
}

int main()
{
    int iValue1 = 0;
    int iValue2 = 0;
    bool bRet = false;
    printf("Enter number : ");
    scanf("%d",&iValue1);
    
    printf("Enter digit (0 to 9): ");
    scanf("%d",&iValue2);
    bRet = ChkDigit(iValue1,iValue2);
    if(bRet == true)
    {
        printf("%d is present in %d\n",iValue2,iValue1);
    }
    else
    {
        printf("%d is not present in %d\n",iValue2,iValue1);
    }

    return 0;
}