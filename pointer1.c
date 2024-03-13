#include<stdio.h>
int main()
{
    int no=11;
    int * iptr = &no;
   
    char ch='A';
    char * cptr = &ch;

    double d=11.11;
    double * dptr = &d;

    printf("%d\n",no);
    printf("%c\n",ch);
    printf("%f\n",d);

    printf("%d\n",&no);
    printf("%d\n",&ch);
    printf("%d\n",&d);

    printf("%d\n",&iptr);
    printf("%d\n",&cptr);
    printf("%d\n",&dptr);
    
    printf("%d\n",*iptr);
    printf("%c\n",*cptr);
    printf("%f\n",*dptr);

    printf("%d\n",sizeof(iptr));
    printf("%d\n",sizeof(cptr));
    printf("%d\n",sizeof(dptr));

    printf("%d\n",sizeof(*iptr));
    printf("%d\n",sizeof(*cptr));
    printf("%d\n",sizeof(*dptr));

   return 0;
}