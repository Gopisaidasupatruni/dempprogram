/*Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. 
* Name:D.Gopisai
 * Date:26-06-2024
 */
#include<stdio.h>
int main(){
           int ch, l=0,i,j,count = 0,k=0;
           char lines[1000];
           char longest[10][1000];
           while( (ch = getchar()) != EOF )
          {
                  count++;
                lines[l++]=ch;
                  if(ch == '\n')
                  {
			 
            if (count > 80 && k < 10) {
                for (i = 0; i < l; i++) {
                    longest[k][i] = lines[i];
                }
                longest[k][l] = '\0'; 
                k++;
            }

count=0;
l=0;
		  }
}

for(i=0;i<k;i++){
			printf("%s",longest[i]);}
}

