#include <stdio.h>

int main() {
    int i[] = {5}; 
    printf("%d", i[0] = ++i[0] == 6);
    return 0;
}

