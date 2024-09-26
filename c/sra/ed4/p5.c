#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rectangle {
    struct point upperLeft;
    struct point lowerRight;
};

int area(struct rectangle r) {
    int width = r.lowerRight.x - r.upperLeft.x;
    int height = r.upperLeft.y - r.lowerRight.y;
    
    if (width < 0 || height < 0) {
        printf("Invalid rectangle coordinates.\n");
        return -1;
    }
    
    return width * height;
}

int main() {
    struct rectangle r = {{2, 5}, {6, 1}}; // Example rectangle
    printf("Area of rectangle: %d\n", area(r));
    return 0;
}

