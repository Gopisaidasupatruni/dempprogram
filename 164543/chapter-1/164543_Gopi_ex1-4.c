/*Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table. 

Author       :Gopisai
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
int main(){

	//celsius to fahrenheit
	printf("celsius to fahrenheit table\n");
	float fahrenheit,c;
	for(c=0;c<100;c=c+VALUE){

		fahrenheit=(9.0/5.0*c)+32.0;

		printf("%2.2f c - %3.0f f\n",c,fahrenheit);
	}
}
/* End of main() */
