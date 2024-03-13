#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int No)
{
    //step 1 Allocate memory for new node
    //step 2 initialise the node
    //step 3 check if LL is empty
    //step 4 if LL is empty store address of new node in First
    //step 5 otherwise store the address of new node inside next pointer of old first node
    //step 6 update first pointer with the address of new node

    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));       //1

    newn->data = No;
    newn->next = NULL;      //2

    if(*Head == NULL)       //3
    {
        *Head = newn;       //4
    }
    else
    {
        newn->next = *Head;     //5
        *Head = newn;       //6
    }
}

void InsertLast(PPNODE Head, int No)
{
    PNODE temp = *Head;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));       //1

    newn->data = No;
    newn->next = NULL;      //2

    if(*Head == NULL)       //3
    {
        *Head = newn;       //4
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn; 
    }
}

void Display(PNODE Head)
{
    printf("Elements of linkedlist are : \n");
    while(Head != NULL)
    {
        printf("| %d | -> ",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

int Count(PNODE Head)
{
    int iCount = 0;
    while(Head != NULL)
    {
        iCount++;
        Head = Head->next;
    }
    return iCount;
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertLast(&First,11);
    InsertLast(&First,21);
    InsertLast(&First,51);
    InsertLast(&First,101);

    Display(First);

    iRet = Count(First);
    printf("Number of nodes are %d\n",iRet);

    InsertFirst(&First,10);
    InsertFirst(&First,20);

    Display(First);

    iRet = Count(First);
    printf("Number of nodes are %d\n",iRet);

    return 0;
}