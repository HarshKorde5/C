#include<stdio.h>

int Countz(char *str)
{
    int iCount = 0;
    while(*str != '\0')
    {
        if(*str == 'z')
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

    iRet = Countz(Arr);        //strlenX(100)

    printf("Number of Digits is : %d\n",iRet);

    return 0;
}