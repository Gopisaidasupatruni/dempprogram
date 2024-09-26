 a declaration, not a definition, and it means the following:

x is a pointer to an array of 10 integers.
Breakdown of the declaration:
int: The data type is int, so we are dealing with integers.
(*x): The parentheses around *x indicate that x is a pointer. This is necessary because of precedence rules in C. Without parentheses, the declaration would be interpreted as an array of 10 pointers to integers.
