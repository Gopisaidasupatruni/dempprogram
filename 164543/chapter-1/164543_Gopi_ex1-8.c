/*Exercise 1-8. Write a program to count blanks, tabs, and newlines. 
 
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

#include<stdio.h>
int main(){
	int blanks=0, tabs=0,newlines=0;
	char ch;
	while((ch=getchar())!=EOF){
		if(ch==' ')
			blanks++;
		if(ch=='\t')
			tabs++;
		if(ch=='\n')
			newlines++;}
	printf("newline %d blanks %d tabs %d\n",newlines,blanks,tabs);
}
/* End of main() */
