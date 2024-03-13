#include<stdio.h>
#include<stdlib.h>

void MaximumMinimum(int Arr[],int iLength)
{
    int iMin = Arr[0],iMax = Arr[0],iCnt = 0;
    for(iCnt = 0; iCnt < iLength; iCnt++)
    {
        if(Arr[iCnt] < iMin)
        {
            iMin = Arr[iCnt];
        }
        if(Arr[iCnt] > iMax)
        {
            iMax = Arr[iCnt];
        }
    }

    printf("Largest number is %d\n",iMax);
    printf("Smallest number is %d\n",iMin);
}

int main()
{
    int iSize = 0,*ptr = NULL,iCnt = 0;

    printf("Enter number of elements : ");
    scanf("%d",&iSize);

    ptr = (int *)malloc(iSize * sizeof(int));

    printf("Enter the elements : \n");
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        printf("Enter element %d : ",iCnt+1);
        scanf("%d",&ptr[iCnt]);
    }

    printf("Elements of the array are : \n");
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        printf("%d\n",ptr[iCnt]);
    }

    MaximumMinimum(ptr,iSize);

    free(ptr);

    return 0;
}