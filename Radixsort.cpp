// Not exactly Radix sort
#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_basedOn_unit_LSD(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[i] % 10) > (a[j] % 10)) {
                swap(&a[i], &a[j]);
            }
        }
    }
}

void sort_basedOn_Tens_digit(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[i] / 10) % 10 > (a[j] / 10) % 10) {
                swap(&a[i], &a[j]);
            }
        }
    }
}
void sort_basedOn_Hundreds_digit(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[i] / 100) % 10 > (a[j] / 100) % 10) {
                swap(&a[i], &a[j]);
            }
        }
    }
}

int main() {
    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(a) / sizeof(a[0]);

    sort_basedOn_unit_LSD(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
    sort_basedOn_Tens_digit(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
    sort_basedOn_Hundreds_digit(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;

    return 0;
}
/*#include<iostream>
using namespace std;


int getMax(int a[], int n) {
    int max = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] > max)
            max = a[i];
    }
    return max;
}


void countingSort(int a[], int n, int exp) {
    int output[n];    // output array
    int count[10] = {0};


    for(int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;


    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];


    for(int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }


    for(int i = 0; i < n; i++)
        a[i] = output[i];
}


void radixSort(int a[], int n) {
    int max = getMax(a, n);


    for(int exp = 1; max / exp > 0; exp *= 10)
        countingSort(a, n, exp);
}

int main() {
    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original Array: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << "\t";
    cout << endl;

    radixSort(a, n);

    cout << "Sorted Array using Radix Sort: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << "\t";
    cout << endl;

    return 0;
}
*/