#include<stdio.h>

int CountDigits(char *str)
{
    int iCount = 0;
    while(*str != '\0')
    {
        if((*str == 'a')&&(*str <= '9'))
        {
            iCount++;
        }
        str++;
    }
    return iCount;
}

int main()
{   
    char Arr[10];
    int iRet = 0;

    printf("Enter String : ");
    scanf("%[^'\n']s",Arr);

    iRet = CountDigits(Arr);        //strlenX(100)

    printf("Number of Digits is : %d\n",iRet);

    return 0;
}