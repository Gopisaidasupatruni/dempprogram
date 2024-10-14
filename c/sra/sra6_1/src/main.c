/** Required header files */
#include <stdio.h>
#include "task1.h"

/* main : Searches the town of a given person */
int main()
{
    char sStr[LENGTH], cVariable;
    ST s1[3];
    int iIndex = 0;
    readPerson(s1); 
    printf("Enter a name to search:\n");
    while ((cVariable = getchar()) != EOF && cVariable != '\n')
        sStr[iIndex++] = cVariable;

    /* Null terminate the input string */
    sStr[iIndex] = '\0';

    /* Search the town of the person */
    char *pResult = searchTown(s1, sStr);

    /* Display the result */
    if (pResult != NULL) {
        printf("This person lives in %s\n", pResult);
    } else {

        printf("Person not found.\n");
    }
    return 0;
}
/* End main*/
