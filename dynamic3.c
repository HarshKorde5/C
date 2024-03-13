#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr = NULL;
    
    //step 1 : Allocate the memory
    ptr = (int *)malloc(sizeof(int)*5); //allocates 20 bytes

    //Step 2 : Use the memory

    ptr=(int *)realloc(ptr,sizeof(int)*7);  //allocates 28 bytes
    ptr=(int *)realloc(ptr,sizeof(int)*3);  //allocates 12 bytes

    //Step 3 : Deallocate the memory
    free(ptr);

    return 0;
}