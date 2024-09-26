#include<stdio.h>
int main()
{
int a=10,*j; void *k; j=k=&a; j++;
k=(int*)k+1;
printf("%p %p ",j,k);
}
