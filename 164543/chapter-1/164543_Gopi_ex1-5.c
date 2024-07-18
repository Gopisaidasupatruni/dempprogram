/*Exercise 1-5. Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0. 
 
Name         :Gopisai
Created Date :24-06-2024
Modified date:24-06-2024
 */
/*REQUIRED HEADER FILES*/
#include<stdio.h>
/*MACRO DEFINITIONS*/
#define VALUE 300
#define STEPS 20
/* FUNCTION PROTOTYPES*/

/* MAIN PROGRAM */
/*
 * main:content of main write here
 */

int main(){
float celsius;
int f;
for(f=VALUE;f>=0;f=f-STEPS){
	celsius=5.0*(f-32)/9.0;
	printf("%3d f - %6.2f c \n",f,celsius);
}
}
/* End of main() /
