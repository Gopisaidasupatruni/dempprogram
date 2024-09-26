 #include<stdio.h>
int main()
{
FILE *ptr; char i;
ptr=fopen("zzz.c","r");
while((i=fgetc(ptr))!=EOF) 
	printf("%c",i);
}

