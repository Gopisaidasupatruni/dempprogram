#include <stdio.h>

volatile int flag = 0;  // flag may be modified elsewhere, such as in an ISR or another thread

void checkFlag() {
    while (flag == 0) {
        // Do something until flag changes
    }
    printf("Flag changed!\n");
}

int main() {
    // Some code that might change 'flag' asynchronously
    flag = 1;  // Assume some external event changes the flag
    checkFlag();  // This would detect the change in the flag
    return 0;
}

