#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr1 = NULL;
    ptr1 = (int *)malloc(sizeof(int)*3);

    ptr1[0] = (int *)malloc(sizeof(int)*4);
    ptr1[1] = (int *)malloc(sizeof(int)*2);
    ptr1[2] = (int *)malloc(sizeof(int)*5);

    int *ptr2 = &ptr1[0];
    int *ptr3 = &ptr1[1];
    int *ptr4 = &ptr1[2];
    
    ptr2 = (int *)malloc(sizeof(int)*4);
    ptr3 = (int *)malloc(sizeof(int)*2);
    ptr4 = (int *)malloc(sizeof(int)*5);

    ptr2[0]= 10;
    ptr2[1] = 20;
    ptr2[2] = 30;
    ptr2[3] = 40;

    ptr3[0] = 50;
    ptr3[1] = 60;

    ptr4[0] = 70;
    ptr4[1] = 80;
    ptr4[2] = 90;
    ptr4[3] = 100;
    ptr4[4] = 110;
    for(int i = 0;i<4;i++)
    {
    printf("%d\n",ptr2[i]);
    }
    return 0;
}