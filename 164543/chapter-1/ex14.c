/*Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input. 
* Name:D.Gopisai
 * Date:25/06/2024
 */
#include<stdio.h>
int main()
{
	char a[20];
	int i,j,c=0,k;
printf("enter a string\n");
scanf("%[^\n]",a);
for(i=0;a[i];i++)
{
                for(j=0;j<i;j++)  {
                 if(a[i]==a[j])
                 break;
                }
                if(j==i)  
                {  
                        for(j=i+1,c=1;a[j];j++)
                        if(a[i] == a[j])
                        c++;
		    printf("%c ----> ",a[i]);
		    for( k=0;k<c;k++)
			    printf("*");
printf("\n");
		}
}
}

