#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

void MAX_Heapify(int a[], int i, int n) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l <= n && a[l] > a[largest]) largest = l;

    if (r <= n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(&a[i], &a[largest]);
        MAX_Heapify(a, largest, n);
    }
}

void BuildHeap(int a[], int n) {
    for (int i = floor(n / 2); i >= 1; i--) {
        MAX_Heapify(a, i, n);
    }
}

void HeapSort(int a[], int n) {
    BuildHeap(a, n);
    for (int i = n; i >= 2; i--) {
        swap(&a[1], &a[i]);
        MAX_Heapify(a, 1, i - 1);
    }
}

void print(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n, a[100];
    srand(time(NULL));
    time_t start = time(NULL);

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        a[i] = rand() % 100;
    }

    printf("Unsorted Order: ");
    print(a, n);

    HeapSort(a, n);

    printf("Sorted Order: ");
    print(a, n);

    time_t end = time(NULL);
    int seconds = difftime(end, start);
    printf("Time taken: %d seconds\n", seconds);

    return 0;
}
