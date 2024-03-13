#include<stdio.h>
#include<stdlib.h>

int CountChar(char *str,char cValue)
{
    int iCount = 0;
    while(*str != '\0')
    {
        if(*str == cValue)
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
    char ch = '\0';
    int iRet = 0;

    printf("Enter String : ");
    scanf("%[^'\n']s",Arr);
    
    fflush(stdin);

    printf("Enter the character : ");
    scanf("%c",&ch);

    iRet = CountChar(Arr,ch);        //strlenX(100)

    printf("Number of Occureneces is : %d\n",iRet);

    return 0;
}