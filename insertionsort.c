// stable sort
// inplace
// adaptive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int a[], int n)

{
    int temp, i, j;
    for (int gap=n/2;gap>0;gap/2){
    for (i = gap; i < n; i++) {
        j = i - 1;
        temp = a[i];
        while (j >= 0 && temp < a[j])

        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}
    printf("Sorted oreder : ");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
}
int main() {
    int n, a[100];
    time_t start = time(NULL);
    printf("Enter the number of Elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10;
    }
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        printf("\t");
    }
    printf("\n");

    insertion(a, n);
    printf("\n");
    time_t end = time(NULL);
    int second = difftime(end, start);
    printf("The time taken is %d", second);

    return 0;
}