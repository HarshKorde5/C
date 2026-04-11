
// Write a C program to display statistics related to memory allocation system. (Use mallinfo() system call).

#include <stdio.h>
#include <malloc.h>

int main()
{
    int *arr = (int *)malloc(100 * sizeof(int)); // allocate memory

    struct mallinfo2 mi;

    mi = mallinfo2();

    printf("Memory allocation system statistics using mallinfo()");

    printf("Arena : Total free space(heap) from system : %ld bytes\n", mi.arena);
    printf("ORDBLKS : Number of free chunks : %ld\n", mi.ordblks);
    printf("SMBLKS : Number of small (fastbin) blocks : %ld\n", mi.smblks);
    printf("HBLKS: Number of memory mapped regions : %ld\n", mi.hblks);
    printf("HBLKHD : Space in memory mapped regions : %ld bytes\n", mi.hblkhd);
    printf("USMBLKS : Maximum total allocated space :  %ld bytes\n", mi.usmblks);
    printf("FSMBLKS : Space avaiable in fastbin blocks : %ld bytes\n", mi.fsmblks);
    printf("UORDBLKS : Total allocated memory currently in use : %ld bytes\n", mi.uordblks);
    printf("FORDBLKS : Total free memory available : %ld bytes\n", mi.fordblks);
    printf("KEEPCOST : Top most releasable space : %ld bytes\n", mi.keepcost);

    return 0;
}