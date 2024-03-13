#include<stdio.h>
#include<stdlib.h>
int main()
{
    int Arr[10];  //static memory allocation
    int size = 0;
    int *ptr = NULL;
    printf("Enter the size of array\n");
    scanf("%d",&size);
    
    //step 1 : Allocate the memory
    ptr = (int *)malloc(sizeof(int)*size);

    //Step 2 : Use the memory

    //Step 3 : Deallocate the memory
    free(ptr);

    return 0;
}