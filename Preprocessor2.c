#include<stdio.h>
#include "PPA.h"

int main()
{
    struct Demo obj;

    printf("Inside main\n");

    printf("Rate of Interest is %f\n",ROI);

    printf("Fees of logic building batch is %d\n",FEES);

    printf("Size of Demo structure is %d\n",sizeof(obj));

    return 0;
}
