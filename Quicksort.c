#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int l, int r) {
    int pivot = a[l];
    int x = l + 1;
    int y = r;

    while (x <= y) {
        while (x <= r && a[x] <= pivot) x++;
        while (y > l && a[y] > pivot) y--;
        if (x < y) {
            swap(&a[x], &a[y]);
        }
    }

    swap(&a[l], &a[y]);
    return y;
}

void quick_sort(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, r);
    }
}

int main() {
    int a[100], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n); 

  
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10;
    }

    printf("Original elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    quick_sort(a, 0, n - 1);  

    printf("\nSorted elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
