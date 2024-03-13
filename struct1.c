#include<stdio.h>

struct Demo 
{
    int i;
    float f;
    int j;
};

int main()
{
    struct Demo obj1;
    struct Demo obj2;

    obj1.i=10;
    obj1.f=10.10;
    obj1.j=11;

    obj2.i=51;
    obj2.f=51.51;
    obj2.j=512;

    printf("%d\n",obj1.i);
    printf("%d\n",obj2.i);

    return 0;
}