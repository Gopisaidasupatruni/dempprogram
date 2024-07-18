/*Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function 
for conversion.  
 * NAME:D.GOPISAI
 * DATE:25-6-2024
 * */
#include<stdio.h>
float conv(float);
int main()
{
	//fahrenheit to celsius
	//float c;
	float i,j=10,c;
	for(i=0;i<100;i=i+j){
c=conv(i);
		printf("%6.2f\n",c);}
}
float conv(float i){
	//printf("fahrenheit to celsius table\n");
	float	c=(i-32)*5.0/9.0;
		return c;
	}


