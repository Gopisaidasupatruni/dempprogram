#include <stdio.h>

#define TAB 4  // Define the number of spaces per tab stop

int main() {
    char ch;
    int count = 0;
    int spaces = TAB;
    
    while ((ch = getchar()) != EOF) {
        if (ch == '\t') {
            int spaces_needed = TAB - (count % TAB);
            for (int i = 0; i < spaces_needed; ++i) {
                putchar(' ');
                count++;
            }
        } else {
            putchar(ch);
            count++;
            if (ch == '\n') {
                count = 0;  // Reset count at the end of each line
            }
        }
    }

    return 0;
}

