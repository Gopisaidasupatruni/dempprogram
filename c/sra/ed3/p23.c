#include<stdio.h>
#define DIM( array, type) sizeof(array)/sizeof(type)
int main()
{
int arr[10];
printf("The dimension of the array is %ld", DIM(arr, int));
}
