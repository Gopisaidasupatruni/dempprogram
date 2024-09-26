#include <stdio.h>

struct point {
    int x;
    int y;
};

    struct point origin, *pp;
int main() {

    origin.x = 0;  // Assign some values to origin
    origin.y = 0;

    pp = &origin;  // Make pp point to the origin

    // Accessing the members of struct through the pointer using both (*pp). and pp->
    printf("origin is (%d, %d)\n", (*pp).x, (*pp).y);  // Using (*pp) dereferencing
    printf("origin is (%d, %d)\n", pp->x, pp->y);      // Using pp-> shorthand

    return 0;
}

