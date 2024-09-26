#include<stdio.h>
int main()
{
	int arr2D[3][3];
	printf("%d", ((arr2D==* arr2D)&&(* arr2D == arr2D[0])));
}
