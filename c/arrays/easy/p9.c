
#include <stdio.h>
int main() {
	int matrix[2][3] = { {5, 6, 7}, {3, 6, 8} };
	matrix[0][2] = 9;
	printf("%d %d",matrix[0][1],matrix[0][2]); 
	return 0;
}

