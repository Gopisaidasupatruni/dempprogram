/*fork*/
#include<stdio.h>
int main()
{
	int ret;
	ret=fork();
	if(ret==0)
	{
		printf("child : %d %d\n",getpid(),getppid());
	}
	else
	{

		printf("paren:%d %d\n",getpid(),getppid());
	}
}
//	system("ls");

