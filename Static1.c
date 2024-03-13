#include<stdio.h>

void Demo()
{
    static int No=10;

    printf("before %d\n",No);

    No++;

    printf("%d\n",No);
}

int main()
{
    Demo();

    Demo();


    return 0;
}