#include<stdio.h>
void main() {
    int *i = (int *)0x400; // i points to the address 0x400
    *i = 0; // set the value of memory location pointed by i
}

