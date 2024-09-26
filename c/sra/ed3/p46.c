#include<stdio.h>
 int main()
{
printf("sizeof (void *) = %ld \n", sizeof( void *));
printf("sizeof (int *) = %ld \n", sizeof(int *));
printf("sizeof (double *) = %ld \n",sizeof(double *));
printf("sizeof(struct unknown *) = %ld \n", sizeof(struct unknown *));
}

