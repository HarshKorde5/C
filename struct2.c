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
   
    struct Demo * ptr = &obj1;

    obj1.i=10;      // . direct member access operator
    ptr->f=10.10;  // -> indirect member access operator
    ptr->j=11;

    printf("%d\n",ptr->i);
    printf("%d\n",ptr->j);
    printf("%f\n",ptr->f);


    return 0;
}