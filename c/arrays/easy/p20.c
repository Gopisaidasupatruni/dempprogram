#include <stdio.h>
int main() {
    char x[] = {'A'};
    x[0] = x[0] + 5; 
    printf("%c", x[0]);
    return 0;
}

