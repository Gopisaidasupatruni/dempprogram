/* using arrays */
#include<stdio.h>
int sum(int a,int b);
int sub(int c,int d);
int main()
{
        int x,y,z,op=1;
        int (*fp[2])(int,int) = {&sum,&sub};
        printf("Enter the x,y values\n");
        scanf("%d%d",&x,&y);
	z=fp[op-1](x,y);
	printf("%d\n",z);
	z=fp[op](x,y);
	printf("%d\n",z);
}
int sum(int a,int b)
{
	int n=a+b;
	return n;
}
int sub(int c,int d)
{
	int m=c-d;
	return m;
}


