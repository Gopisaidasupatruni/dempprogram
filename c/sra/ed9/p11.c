#include <stdio.h>

int main() {
    struct {
        char a;
        short b;
        int c;
    } temp;

    printf("Size of structure: %zu\n", sizeof(temp));
    return 0;
}

