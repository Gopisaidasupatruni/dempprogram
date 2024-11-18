#include <stdio.h>

void main() {
    int k = 1, n[5], i, sum = 0;
    for (i = 0; i < 5; i++) {
        sum = i + ++k;
        n[i] = sum + ++k;
    }
    printf("%d\n", n[4]);
}

