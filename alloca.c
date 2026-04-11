// Write a C program to create variable length arrays using alloca() system call.

#include <stdio.h>
#include <alloca.h>

int main() {
    int n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)alloca(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}