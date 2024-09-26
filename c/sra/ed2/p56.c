#include<stdio.h>
typedef struct errorType{int warning, error, exception;}error;
int main()
{
error g1; g1.error=1;
printf("%d",g1.error);
}
