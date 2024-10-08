#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int add(int,int );
int sub(int,int );
int main(int argc,char *argv[])
{
	if(argc!=4)
	{
		printf("usage ./exe fun_name int int \n");
	}
	int sum1,sub1;
	int n1=atoi(argv[2]);
	int n2=atoi(argv[3]);

	char str[20]="add";
	char str1[20]="sub";

	if(strcmp(str,argv[1])==0){
	sum1=add(n1,n2);

	printf("%d",sum1);
	}
	else if(strcmp(str1,argv[1])==0)
	{
	sub1=sub(n1,n2);
	printf("%d",sub1);
	}
         else
		 printf("enter correct fun name \n");

return 0;
}

int add(int n1,int n2)
{
	int sum=n1+n2;
	return sum;
}
int sub(int n1,int n2)
{
	int sum=n1-n2;
	return sum;
}
