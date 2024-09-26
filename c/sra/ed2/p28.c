#include <stdio.h>

void fun(int **k) {
    int a = 0; 
    *k = &a;  // Assign the address of 'a' to the pointer 'k' which points to 'j'
}

int main() {
    int *j;
    fun(&j);  // Pass the address of 'j' to the function
    printf("Address of a: %p\n", j);  // Print the address of 'a' stored in 'j'
    printf("Value of a through j: %d\n", *j);  // Dereference 'j' to get the value of 'a'
    return 0;
}

