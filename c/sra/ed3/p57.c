#include<stdio.h>
#define swap(a,b)  a=a+b;b=a-b;a=a-b;
void main()
{
int m=5, n=10;
swap (m,n);
printf("%d %d\n",m,n);
//swap2(m,n);
}
