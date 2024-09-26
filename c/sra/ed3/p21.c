#include<stdio.h>
int main()
{
	int a=2,*f1,*f2;
	f1=f2=&a;
	*f2+=*f2+=a+=2.5;
	printf("%d %d %d\n",a,*f1,*f2);
}
