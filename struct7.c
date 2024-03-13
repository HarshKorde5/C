#include<stdio.h>
#pragma pack(1)
struct Demo 
{
    int no;
    char ch;
    float f;
    int i;

};

int main()
{
    struct Demo obj1;
    printf("%d\n",sizeof(obj1));
    return 0;
}