/*Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? 
Name    : Gopisai
created :1 July,2024
Modified:1 July,2024 */
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
int count=1;
int spaces =TAB;
while((ch=getchar())!=EOF){
if(ch==' '){
		count++;
if(count>=spaces){
        spaces= spaces+4;
	printf("\\t");
}
/*if(count<spaces-1)
	putchar(ch);*/
}
/*else if(ch=='\n')
	count=0;*/
else{
putchar(ch);

}
}
}
/* End  main() */
