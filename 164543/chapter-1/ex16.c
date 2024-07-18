/*Exercise 2-16. Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text.
 * Name:D.Gopisai
 * Date:25-06-2024
 */
#include<stdio.h>
void copy(char to[],char from[]);
int main(){
           int ch, l,file_size = 0, line = 0, big_line = 0, big_line_length = 0, count = 0;
           char lines[50];
           char longest[50];
           for(l=0; (ch = getchar()) != EOF;l++ )
          {
                  file_size++;
                  count++;
                lines[l]=ch;
                  if(ch == '\n')
                  {
                          line++;

                          if(count > big_line_length)
                          {

                                  big_line = line;
                                  big_line_length = count;
                                  copy(longest,lines);
}
count=0;
l=0,l--;
}
}
			 printf("longest line is- %s",longest);
		  
         printf("big_line = %d  big_line_length = %d\n",big_line,big_line_length);
}
void copy(char to[],char from[]){
	int i;
	i=0;
	while((to[i]=from[i])!='\0')
		++i;
}
