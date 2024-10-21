#include<stdio.h>
#include<unistd.h>
//#include<fcntl.h>
int main()
{
	if(fork()==0)
	{
		printf("child\n");
		printf("%d",getpid());
		printf("%d",getppid());
	}
	else
	{
		printf("parent\n");
	        while(1);	
		printf("%d",getpid());
	}

}
