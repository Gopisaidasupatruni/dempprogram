/*Exercise 1-3. Modify the temperature conversion program to print a heading above the table. 
Nmae         :Gopisai
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
	//fahrenheit to celsius
	float i;
	float celsius;
	printf("fahrenheit to celsius table:\n");
	for(i=0;i<100;i=i+VALUE){
		celsius=(i-32)*5.0/9.0;
		printf("%2.0f - %6.2f\n",i,celsius);
	}
}
/* End of main() */

