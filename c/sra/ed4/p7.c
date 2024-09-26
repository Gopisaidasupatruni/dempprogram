#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *duplicate_str(char*);
int main()
{
	char str[]="abcd";
	char *p;
	p=duplicate_str(str);
	printf("%s",p);
}
char *duplicate_str(char*s)
{
	int n=strlen(s);
	char *p=malloc(n+1);
	if(p==NULL)
		return NULL;
	char *temp=p;
	while(*s!='\0')
		*p++=*s++;
	*p='\0';
	return temp;
}
