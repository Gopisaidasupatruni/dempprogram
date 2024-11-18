#include <stdio.h>
int main() {
    int arr[50] = {0, 1, 2, [47] = 47, 48, 49};
    printf("%d %d", arr[47],arr[48]);
    return 0;
}

