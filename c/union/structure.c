#include <stdio.h>

/* declaring structure */
struct test1 {
    unsigned int x;
    unsigned short int y;
    unsigned  char z;
    unsigned int a;
} Test1;

int main()
{
    /* finding size using sizeof() operator */
    int size1 = sizeof(Test1);
    Test1.x = 0xaabbccdd;

    /* Print the value of x in hexadecimal format */
    printf("Value of Test1.x: 0x%x\n", Test1.x);

    // Print the size of Test1
    printf("Size of test1: %d\n", size1);

    return 0;
}
