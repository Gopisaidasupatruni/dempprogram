#include <stdio.h>
#include <stdlib.h>

struct time {
    int hours;
    int min;
    int sec;
};

int main() {
    struct time t;

    // Allocate memory for the integer pointers inside the structure

    // Now you can safely store values into the pointers
    printf("Enter value for seconds: ");
    scanf("%d", &t.sec);  // No need to dereference, t->sec is a pointer

    // Print the value stored in t->sec
    printf("Seconds: %d\n", t.sec);

    // Free the allocated memory for the pointers

    return 0;
}

