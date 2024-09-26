#include<stdio.h>
int main()
{
	int i = 258;
int *iPtr = &i;
printf("%d %d", *((char*)iPtr), *((char*)iPtr+1) );
}
