#include<stdio.h>

int CountSpace(char *str)
{
    int iCount = 0;
    while(*str != '\0')
    {
        if(*str == ' ')
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

    iRet = CountSpace(Arr);        //strlenX(100)

    printf("Number of space is : %d\n",iRet);

    return 0;
}