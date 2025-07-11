#include <stdio.h>
long int table[100] = {0};

long int FibM(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else if (table[n] == 0) {
        table[n] = FibM(n - 1) + FibM(n - 2);
    }
    return table[n];
}

int main() {
    long int result = FibM(7);
    printf("Fib series num: %ld ", result);

    return 0;
}
