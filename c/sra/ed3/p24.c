
#include<stdio.h>
	 int DIM(int array[])
{
return sizeof(array)/sizeof(int );
}

int main()
{
int arr[10];
printf("The dimension of the array is %d", DIM(arr));
}
