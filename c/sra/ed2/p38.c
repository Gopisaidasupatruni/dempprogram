#include<stdio.h>
int main()
{
	void *v;
	int integer=2;
	int*i=&integer;v=i;
	printf("%d",*(int*)v);
}
