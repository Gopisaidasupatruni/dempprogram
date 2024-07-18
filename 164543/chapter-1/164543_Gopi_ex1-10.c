/*Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\.  makes tabs and backspaces visible in an unambiguous way. 
 *
Name         :Gopisai
Created Date :24-06-2024
Modified date:24-06-2024
 */
/*REQUIRED HEADER FILES*/
#include<stdio.h>

/* FUNCTION PROTOTYPES*/

/* MAIN PROGRAM */
/*
 * main:content of main write here
*/
int main(){
int i,j;
char ch;
int blanks=0;
while((ch=getchar())!=EOF){
	if(ch=='\t')
	{
	printf("\\t");	
	}
	else if(ch=='\b')
	{
		printf("\\b");
		
	}
	else if(ch=='\\')
	{
		printf("\\\\");
	}
	else 
		putchar(ch);
}
}
/*End of main()*/	
