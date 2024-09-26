#include<stdio.h>
int  main()
{
static char names[5][20]={"pascal","ada","cobol","fortran","perl"};
int i;
char *t;
t=names[3];
names[3]=names[4];
names[4]=t;
for(i=0;i<=4;i++)
	printf("%s",names[i]);

}
/*In C, arrays cannot be assigned to each other using the = operator. Each names[i] is a fixed-size array of 20 characters, and arrays in C are not directly assignable.

Problem:
The line names[3] = names[4]; is invalid because you are attempting to assign one array to another, which is not allowed in C. The array names in C are non-modifiable l-values, meaning you can't assign to them like you can with pointers.
Solution:
Instead of assigning arrays, you can use strcpy()*/
