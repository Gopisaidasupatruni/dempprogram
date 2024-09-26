#include<stdio.h>
int one_d[3]={1,2,3};
int main()
{
int *ptr; ptr=one_d; ptr+=3;
printf("%d",*ptr);
}
