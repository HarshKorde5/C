#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head,int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)       //LL is empty
    {
        *Head = newn;
    }
    else        //LL contains atleast one element             
    {
        newn->next = *Head;
        *Head = newn;
    }
}
void Display(PNODE Head)
{
    printf("Elements of LinkedList are : \n");

    while(Head != NULL)
    {
        printf("| %d | -> ",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");

}

int Summation(PNODE Head)
{
    int iSum = 0;

    while(Head != NULL)
    {
        iSum = iSum + (Head -> data);
        Head = Head -> next;
    }

    return iSum;
}

int Maximum(PNODE Head)
{
    int iMax = Head->data;

    while(Head != NULL)
    {
        if(Head->data > iMax)
        {
            iMax = Head->data;
        }
        Head = Head -> next;
    }

    return iMax;
}

int Minimum(PNODE Head)
{
    int iMin = 0;

    
    iMin = Head->data;

    while(Head != NULL)
    {
        if(Head->data < iMin)
        {
            iMin = Head->data;
        }
        Head = Head -> next;
    }

    return iMin;
}


void SumDigits(PNODE Head)
{
    int iNo = 0;
    int iSum = 0;
    int iDigit = 0;

    while(Head != NULL)
    {
        iNo = Head -> data;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        printf("%d\n",iSum);

        iSum = 0;
        Head = Head -> next;
    }
}

void CheckPerfect(PNODE Head)
{
    int iNo = 0;
    int iSum = 0;
    int iCnt = 0;
    while(Head != NULL)
    {
        iNo = Head -> data;
        
        for(iCnt = 1; iCnt <= iNo/2; iCnt++)
        {
            if((iNo % iCnt)== 0)
            {
                iSum = iSum + iCnt;
            }
        }
        if(iSum == iNo)
        {
            printf("%d is perfect\n",iNo);
        }

        iSum = 0;
        Head = Head -> next;
    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,111);
    InsertFirst(&First,101);
    InsertFirst(&First,6);
    InsertFirst(&First,21);
    InsertFirst(&First,11);

    Display(First);

    iRet = Summation(First);
    printf("Summation is : %d\n",iRet);

    iRet = Maximum(First);
    printf("Maximun is : %d\n",iRet);

    iRet = Minimum(First);
    printf("Minimum is : %d\n",iRet);

    SumDigits(First);
    CheckPerfect(First);
    return 0;
}