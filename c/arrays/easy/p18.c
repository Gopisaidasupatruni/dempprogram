#include <stdio.h>

int main() {
    int a[3] = {10, 20, 30};
    int *p = a + 2;
    printf("%d\n", p[-1]);
    return 0;
}

