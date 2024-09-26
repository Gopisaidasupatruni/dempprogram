#include<stdio.h>
int aaa() {printf("Hi");}
int bbb(){printf("hello");}
int ccc(){printf("bye");}
int main()
{

int ( * ptr[3]) (); 
ptr[0] = aaa; 
ptr[1] = bbb; 
ptr[2] =ccc; 
ptr[2]();
}

