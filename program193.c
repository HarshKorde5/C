#include<stdio.h>

void strncpyX(char *src,char *dest, int iLength)
{
    while((*src != '\0')&&(iLength != 0))
    {
        *dest = *src;
        src++;
        dest++;
        iLength--;
    }
    *dest = '\0';
}

int main()
{
    int iNo = 0;
    char Arr[20];
    char Brr[20] = "Demo";

    printf("Enter string : \n");
    scanf("%[^'\n']s",Arr);

    printf("Enter number of letters you want to copy : ");
    scanf("%d",&iNo);

    strncpyX(Arr,Brr,iNo);

    printf("String after copy is : %s\n",Brr);
    
    return 0;
}