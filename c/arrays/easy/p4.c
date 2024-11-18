#include<stdio.h>
int main(void)
{
int arr[5] = { 10, 20, 30, 50, 70 };
int *ptr = (int*)(&arr + 1);
printf("%d %d\n", *(arr + 2), *(ptr - 2));
return 0;
}
