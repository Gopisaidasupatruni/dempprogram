#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
char *k1="hitechskill.com"; char 
*k2; k2=(char*)malloc(20); 
memset (k2, 0, 20); while(*k2++ 
= *k1++); printf("%s\n",k2);
}
