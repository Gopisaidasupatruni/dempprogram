/*Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. 
* Name:D.Gopisai
 * Date:26-06-2024
 */
#include<stdio.h>
void copy(char to[],char from[]);
int main(){
           int ch, l=0,count = 0,k=0;
           char lines[1000];
           char longest[500];
           while( (ch = getchar()) != EOF )
          {
                  count++;
                lines[l++]=ch;
                  if(ch == '\n')
                  {

                          if(count > 80)
                          {
			  lines[l++]='\0';
				  
                                  copy(longest,lines);

			 printf("line is-%s",longest);
			  }
count=0;
l=0;
}
}		  
}
void copy(char to[],char from[]){
	int i;
	i=0;
	while((to[i]=from[i])!='\0')
		++i;
}
