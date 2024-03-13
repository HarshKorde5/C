#include<stdio.h>

void strncatX(char *src,char *dest, int iLength)
{
    //1 : travel till end of dest
    while(*dest != '\0')
    {
        dest++;
    }

    //2 : copy data from src to dest
    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
        
        iLength--;
        if(iLength == 0)
        {
            break;
        }
    }

    //3 : write '\0' at the end of dest
    *dest = '\0';
}

int main()
{
    int iNo = 0;
    char Arr[20];
    char Brr[20] = "Demo";

    printf("Enter string : \n");
    scanf("%[^'\n']s",Arr);

    printf("Enter number of letters you want to concate : ");
    scanf("%d",&iNo);

    strncatX(Arr,Brr,iNo);

    printf("String after copy is : %s\n",Brr);
    
    return 0;
}