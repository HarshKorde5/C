#include<stdio.h>
int main()
{
    char ch='A';
    int i=10;
    float f=2.2;
    double d=23.23;

    char * cp=&ch;
    int * ip=&i;
    float * fp=&f;
    double * dp=&d;

    void * vp=NULL;
    vp=&ch;

    printf("%c\n",*(char *)vp);

    vp=&i;
    printf("%d\n",*(int *)vp);
    return 0;
}