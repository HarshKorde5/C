#include<stdio.h>       //IO
#include<stdlib.h>      //Memory Management

float Average(int Arr[], int iLength)
{
    int iCnt = 0;
    int iSum = 0;
    for(iCnt = 0;iCnt < iLength;iCnt++)
    {
        iSum = iSum + Arr[iCnt];
    }
    return ((float)iSum/(float)iLength);
}

int main()              //Entry point function
{
    int iSize = 0;      //To store size of array
    int *ptr = NULL;    //To store address of array
    int iCnt = 0;       //Loop Counter
    float fRet = 0;
    //Step 1 : Access the number of elements from the user
    printf("Enter number of elements : ");
    scanf("%d",&iSize);

    //Step 2 : Allocate memory dynamically
    ptr = (int *)malloc(iSize * sizeof(int));

    //Step 3 : Accept the values from user
    printf("Enter the elements : \n");
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        scanf("%d",&ptr[iCnt]);
    }

    printf("Elements of array are : \n");
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        printf("%d\n",ptr[iCnt]);
    }

    //Step 4 : Pass the array to the function
    fRet = Average(ptr,iSize);
    printf("Average is : %f",fRet);
    //Step 6 : Deallocate the memory of array
    free(ptr);

    return 0;       //Return success to OS
}