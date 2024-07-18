/*Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
input is this\tis\ta\ttest
Name : Gopisai
created :1 July,2024
Modified:1 July,2024
*/
/** REQUIRED HEADER FILES **/
#include<stdio.h>
/** MACROS DEFINITIONS **/
#define TAB 4
/** FUNCTION PROTOTYPES**/

/* MAIN PROGRAM */
/*
 * main:(content of main write here)
 */
int main(){
char ch;
int count;
while((ch=getchar())!=EOF){
if(ch=='\t'){
            int spaces= TAB - (count % TAB);
	while(spaces){
	putchar(' ');
		--spaces;
		count++;
	}
}
else{
putchar(ch);
count++;
if(ch=='\n')
	count=0;
}
}}
/* End  main() */
