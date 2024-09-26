#include <stdio.h>
#include <stdlib.h>

struct time {
    int *hours;
    int *min;
    int *sec;
};

int main() {
    // Create a pointer to a structure
    struct time *t = (struct time *)malloc(sizeof(struct time));

    // Allocate memory for the integer pointers inside the structure
    t->hours = (int *)malloc(sizeof(int));
    t->min = (int *)malloc(sizeof(int));
    t->sec = (int *)malloc(sizeof(int));

    // Now you can safely store values into the pointers
    printf("Enter value for seconds: ");
    scanf("%d", t->sec);  // No need to dereference, t->sec is a pointer

    // Print the value stored in t->sec
    printf("Seconds: %d\n", *(t->sec));

    // Free the allocated memory for the pointers
    free(t->hours);
    free(t->min);
    free(t->sec);
    free(t);  // Free the structure itself

    return 0;
}

