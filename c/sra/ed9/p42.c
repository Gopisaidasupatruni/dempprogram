#include <stdio.h>
#include <string.h>

char *gxxx() {
    static char xxx[1024];  // Static array with 1024 bytes
    return xxx;
}

int main() {
    char *g = "string";  // Pointer to string literal
    
    strcpy(gxxx(), g);  // Copy "string" to the static array returned by gxxx
    g = gxxx();  // Now g points to the static array returned by gxxx
    
    strcpy(g, "oldstring");  // Copy "oldstring" to the same static array
    printf("The string is : %s\n", gxxx());  // Print the contents of the static array
    
    return 0;
}

