#include<stdio.h>
int main()
{
	extern out;
	printf("%d",out);
}
int out=100;
