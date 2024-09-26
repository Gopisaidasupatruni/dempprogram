#include <stdio.h>

int main() {
    //int i = 10, j = 20;
    
  //  // Correct the logic here (assuming we want to assign j based on conditions):
    //j = (j != 0) ? ((i != 0) ? i : j) : j;  // This is a simplified version of the ternary condition.
    int i=10,j=20;
j=j?(i,j)?i:j:j;
//printf(“%d %d”,i,j);

    printf("%d %d\n", i, j);
    return 0;
}

