#include<stdio.h>

int CountSmall(char *str)
{
    int iCount = 0;
    while(*str != '\0')
    {
        if((*str >= 'a')&&(*str <= 'z'))
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

    iRet = CountSmall(Arr);        //strlenX(100)

    printf("Number of small letters is : %d\n",iRet);

    return 0;
}