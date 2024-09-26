#include<stdio.h>
#define TRUE 1
#define FALSE -1//In C, any non-zero value is treated as true
#define NULL 0
int main()
{
	if(NULL)
		puts("NULL");
	else if(FALSE)
		puts("TRUE");
	else
		puts("FALSE");
}
