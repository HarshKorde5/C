#include<stdio.h>
#include<string.h>

int main()
{   
    char Arr[10];
    int iRet = 0;

    printf("Enter your name : ");
    scanf("%[^'\n']s",Arr);

    iRet = strlen(Arr);

    printf("Length o string is : %d\n",iRet);
    return 0;
}