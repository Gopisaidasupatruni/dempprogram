#include<stdio.h>
void swap(int *a, int *b)
{
*a ^= *b, *b ^= *a, *a ^= *b;
}
int main()
{
 int x=10,y=8; 
swap(&x,&y);
printf("%d %d\n",x,y);
}
