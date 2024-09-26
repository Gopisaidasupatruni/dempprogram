#include<stdio.h>
int main()
{
int i=400,j=300; printf("%d..%d");
}
/*Since the format specifiers in printf() expect arguments, and no arguments are provided, this results in undefined behavior. Depending on the system and compiler, this can result in:
Random output or garbage values being printed.
A runtime error.
Or possibly no output at all.*/
