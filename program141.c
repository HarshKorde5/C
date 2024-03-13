/*
    Input : 
    Row : 6
    Col : 6

    Output:
    A 
    A B
    A B C
    A B C D
    A B C D E
    A B C D E F
*/

#include<stdio.h>

void Display(int iRow, int iCol)
{
        if(iRow != iCol)
    {
        printf("Invalid input\n");
        return;
    }
    int i = 0, j = 1;
    char ch = '\0';
    for(i = 1, ch = 'a'; i <= iRow; i++, ch++)
    {
        for(j = 1; j <= iCol; j++)
        {
            if(i == j)
            {
                printf("*\t");
            }
            else
            {
                printf("%c\t",ch);
            }
        }
        printf("\n");
    }
}

int main()
{
    int iValue1 = 0, iValue2 = 0;

    printf("Enter number of rows : ");
    scanf("%d",&iValue1);

    printf("Enter number of columns : ");
    scanf("%d",&iValue2);

    Display(iValue1,iValue2);

    return 0;
}