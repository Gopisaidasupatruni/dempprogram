#include<stdio.h>
int main()
{
int n=2;
int sum=5;
switch(n)
{
case 2:sum=sum-2; break;
case 3:sum*=5; break;
default :sum=0;
}
printf("%d",sum);

}
