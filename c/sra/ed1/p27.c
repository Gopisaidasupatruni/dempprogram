#include<stdio.h>
#define MAN(x,y) (x)>(y)?(x):(y)
int main() {
int i=10, j=5;
int k=0; k=MAN(i++,++j);
printf("%d %d %d",i,j,k);
}

