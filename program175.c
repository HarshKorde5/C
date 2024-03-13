#include<stdio.h>

void Display(char *str)
{
    int iSmall = 0,iCap = 0;
    while(*str != '\0')
    {
        if((*str >= 'a')&&(*str <= 'z'))
        {
            iSmall++;
        }
        else if((*str >= 'A')&&(*str <= 'Z'))
        {
            iCap++;
        }
        str++;
    }

    printf("Small case characters count : %d\n",iSmall);
    printf("Capital case characters count : %d\n",iCap);

}

int main()
{
    char Arr[20];

    printf("Enter string : \n");
    scanf("%[^'\n']s",Arr);

    Display(Arr);
    
    return 0;
}