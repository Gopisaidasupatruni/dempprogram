#include<stdio.h>
int main()
{
	int a[10] = {1,2,3,4};
	printf("%d", !(a[0]&a[1]&a[2]++)*10);
}

