/* Basic program to understanf how function pointer works
 * Swapping Two numbers
*/
#include<stdio.h>
/* Function pointer : A pointer which holds function address */
/* Syntax : return_type (*pointer_name)(parameter_types); */
void swap(int*,int*);
int main()
{
	int iNum1=10,iNum2=20;

	void (*fp)(int*,int*);
	fp=&swap;
	fp(&iNum1,&iNum2);
	printf("%d %d",iNum1,iNum2);
}
void swap(int *a ,int *b)
{
	int itemp=*a;
	*a=*b;
	*b=itemp;
}
