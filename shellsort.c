#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell_sort(int a[], int n)

{
    for (int gap = n / 2; gap > 0; gap/=2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
        
        
    }
}
void print(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        printf(" ");
    }
}
int main() {
    int n, a[100];
    srand(time(NULL));
    time_t start = time(NULL);
    printf("Enter the number of Elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
    printf("Unsorted Order : ");
    print(a,n);


    shell_sort(a, n);

    printf("\n");
    printf("Sorted Order : ");
    print(a,n);
    time_t end = time(NULL);
    int second = difftime(end, start);
    printf("\nThe time taken is %d", second);

    return 0;
}