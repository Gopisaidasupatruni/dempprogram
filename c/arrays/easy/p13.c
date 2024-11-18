#include<stdio.h>
#include<string.h>
int main(){   
	   char x[] = "Hi\0Hello";  
	   printf("%ld %ld", strlen(x), sizeof(x));  
	}  

