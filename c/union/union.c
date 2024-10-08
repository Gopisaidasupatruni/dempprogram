#include <stdio.h>

/* declaring union */
union test1 {
    unsigned int x;
    unsigned short int y;
    unsigned  char z;
} Test1;

int main()
{
    /* finding size using sizeof() operator */
    int size1 = sizeof(Test1);
    Test1.x = 0xaabbccdd;

    /* Print the value of x in hexadecimal format */
    printf("Value of Test1.x: 0x%x\n", Test1.x);
    printf("Value of Test1.y: 0x%x\n", Test1.y);
    printf("Value of Test1.z: 0x%x\n", Test1.z);

    // Print the size of Test1
    //printf("Size of test1: %d\n", size1);

    return 0;
}
/*Address  |  Value
---------|---------
0x00     |  0xdd
0x01     |  0xcc
0x02     |  0xbb
0x03     |  0xaa*/
