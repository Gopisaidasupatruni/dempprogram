#include<stdio.h>
//32. What will be the output?
#define one 0
int main(){
#ifdef one
printf("one is defined ");
#endif
#ifndef one
printf("one is not defined ");
#endif
}
