#include<stdio.h>
#include<stdbool.h>
bool Checkz(char *str)
{
    int iCount = 0;
    while(*str != '\0')
    {
        if(*str == 'z')
        {
            break;
        }
        str++;
    }
    if(*str == '\0')
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{   
    char Arr[10];
    bool bRet = false;

    printf("Enter String : ");
    scanf("%[^'\n']s",Arr);

    bRet = Checkz(Arr);        //strlenX(100)

    if(bRet == true)
    {
        printf("z is present\n");
    }
    else
    {
        printf("z is not present\n");
    }

    return 0;
}