/*Exercise 1-11. How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any? 

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
	int word_count=0,lines=0,count=0;
	int ch;
	while((ch=getchar())!=EOF){
		count++;
	if(ch=='\n')
		lines++;
		if(ch=='\n'||ch==' ' ||ch=='\t')
			word_count++;
		
	}
	printf("word count %d line count %d characters %d\n",word_count,lines,count);
}
/* End of main() */
