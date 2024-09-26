#include<stdio.h>
void abc(char a[]);
int main()
{
	char a[100]; a[0]='a';a[1]='b';a[2]='c';a[4]='d';
abc(a);
}
void abc(char a[]){ a++;
printf("%c",*a); a++;
printf("%c",*a);

}
