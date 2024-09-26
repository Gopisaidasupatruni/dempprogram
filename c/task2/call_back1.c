/* Call back function */
#include<stdio.h>

int sum(int a,int b);
int sub(int a,int b);
void display(int(*fun)(int,int));
int main()
{
	int iNum;
	printf("enter the operation 1 -> sum  2 -> sub \n");
	scanf(" %d",&iNum);
	switch(iNum)
	{
		case 1:
			display(sum);
			break;
		case 2:
			display(sub);
			break;
		default:
			printf("invalid option\n");
	}
	
}
void display(int (*fun)(int,int))
{
	int iResult=(*fun)(10,5);
	printf("%d\n",iResult);
}
int sum(int a,int b)
{
	int itemp=a+b;
	return itemp;
}
int sub(int a,int b)
{
	int itemp=a-b;
	return itemp;
}
