 #include<stdio.h>
int main()
{
int a[2][2][2] = { {10,2,3,4}, {5,6,7,8} };
int *p,*q; p=&a[2][2][2];
*q=***a;
printf("%d ---%d",*p,*q);
}
/*Pointer Issue:

The statement p = &a[2][2][2]; is invalid because you're accessing an out-of-bounds index.
The array a is declared as a[2][2][2], meaning valid indices range from 0 to 1 for each dimension. However, a[2][2][2] accesses the third element in each dimension, which does not exist. This is undefined behavior and leads to a segmentation fault.
Uninitialized Pointer q:

You are assigning a value to *q, but q has not been initialized to point to a valid memory location. The pointer q is a wild pointer at this point, and dereferencing it results in undefined behavior, often leading to a segmentation fault.*/
