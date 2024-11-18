#include<stdio.h>
int main()
{
	int a[3][3] = { {10,20,30}, {40,50,60}, {70,80,90} };
	int (*q)[3] = a;


	printf("(*q)[0] = %d\n",(*q)[0]);
	printf("*q[1] = %d\n",*q[1]);
	printf("(*q)[1] = %d\n",(*q)[1]);
}
