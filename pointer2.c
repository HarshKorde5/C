#include<stdio.h>
int main()
{
    int no=11;

    int *p=&no;

    int **q=&p;

    int ***r=&q;

    int ****a=&r;

    int *****b=&a;

    int ******c=&b;

    return 0;
}