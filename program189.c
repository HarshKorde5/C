#include<stdio.h>

void strcatX(char *src,char *dest)
{
    //1 : travel till end of dest
    while(*dest != '\0')
    {
        dest++;
    }
    *dest = ' ';        //add space if needed
    dest++;
    //2 : copy data from src to dest
    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    //3 : write '\0' at the end of dest
    *dest = '\0';
}

int main()
{
    char Arr[20];
    char Brr[20] = "Demo";

    printf("Enter string : \n");
    scanf("%[^'\n']s",Arr);

    strcatX(Arr,Brr);

    printf("String after copy is : %s\n",Brr);
    
    return 0;
}