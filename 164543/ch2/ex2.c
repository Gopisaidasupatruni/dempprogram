/*Question
 * Write a loop equivalent to the for loop above without using && or ||.
 *
 *for loop- i < lim-1 && (c=getchar()) != '\n' && c != EOF 
 for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) 
  s[i] = c; 
NAME:Gopisai
Date:6/21/2024
 */
#include<stdio.h>
int main()
{
	int lim=10;
	int i;
	char s[10];
	for(i=0;i<lim-1;i++){
	char c=getchar();
	if(c=='\n')
		break;
	else if (c==EOF)
		break;
	else
	s[i]=c;
	}
	printf("%s",s);

	      
}
