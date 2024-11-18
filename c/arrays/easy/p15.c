#include <stdio.h>
int main() {
    int a[2][3] = { {1, 2} };
    
    printf("%d", a[0][a[0][0]]);
    return 0;
}

