/*Exercise 1-12. Write a program that prints its input one word per line. 

Name         :Gopisai
Created Date :24-06-2024
Modified date:24-06-2024
 */
/*REQUIRED HEADER FILES*/
#include<stdio.h>
/*MACRO DEFINITIONS*/
#define VALUE 10
/* FUNCTION PROTOTYPES*/

/* MAIN PROGRAM */
/*
 * main:content of main write here
*/
int main()

{
	char s;
	printf("enter a string\n");
	while((s=getchar())!=EOF){
		if(s==' '||s=='\n'||s=='\t')
			putchar('\n');
		else
			putchar(s);

		}
}
/*End of main()*/



