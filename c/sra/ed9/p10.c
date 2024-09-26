#include<stdio.h>
int main()
{
int a[5],i,*ip; 

ip=a; printf("%d",*(ip+3*sizeof(int)));
}
