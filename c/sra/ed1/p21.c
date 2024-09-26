#include<stdio.h>
int main()
{
char *p="hai friends",*p1; p1=p;
while(*p!='\0') ++*p++; printf("%s %s",p,p1);
}
/*The segmentation fault in your code occurs because you're modifying a string literal, which is stored in read-only memory. In C, string literals are generally stored in read-only sections of memory, and attempting to modify them leads to undefined behavior, typically causing a segmentation fault.*/
