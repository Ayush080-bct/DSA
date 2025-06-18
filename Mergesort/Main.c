#include <stdio.h>
#include "Myfloor_func.h"

int main() {
    int a[] = {11,17,12,3,4,18,100,5,19};
    int n = sizeof(a) / sizeof(a[0]);

    printf("original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    mergesort(a, 0, n - 1);

    printf("sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");


    return 0;
}
