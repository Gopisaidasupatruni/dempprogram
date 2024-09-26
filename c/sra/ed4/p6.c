#include <stdbool.h>

bool isPointInside(struct rectangle r, struct point p) {
    return (p.x >= r.upperLeft.x && p.x <= r.lowerRight.x &&  // Check x-coordinate
            p.y <= r.upperLeft.y && p.y >= r.lowerRight.y);   // Check y-coordinate
}

int main() {
    struct rectangle r = {{2, 5}, {6, 1}};  // Rectangle with corners (2, 5) and (6, 1)
    struct point p = {4, 3};  // Point to check
    
    if (isPointInside(r, p)) {
        printf("Point lies within the rectangle.\n");
    } else {
        printf("Point is outside the rectangle.\n");
    }
    
    return 0;
}

