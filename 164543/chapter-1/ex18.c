/*Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, 
and to delete entirely blank lines. */
#include<stdio.h>
int main()
{
char ch,a[100];
int i=0;
while((ch=getchar())!=EOF){
	a[i++]=ch;
if(ch==' '||ch=='\t')
{
i--;
}
}
a[i+1]='\0';
int j=0,k;
for(j=0;a[j]!='\0';j++){
	
if((a[j]=='\n') && (a[j+1]=='\n')){
	for(k=j;a[k];k++)
	a[k]=a[k+1];
j--;}}
printf("%s",a);
}		
