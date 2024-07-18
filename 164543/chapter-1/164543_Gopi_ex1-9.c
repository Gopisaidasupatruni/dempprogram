/*Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. 
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
	if(ch==' ')
		blanks++;
	if(ch!=' '){
	if(blanks>=1)
		putchar(' ');
		putchar(ch);
		blanks=0;
	}
}
}
/*End of main*/	
