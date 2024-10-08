/*
 * This program asks the user to enter the name and the home town of 3 persons. Name and
home town are stored in a structure Person. The 3 persons are stored in an array. Afterwards, the
program asks the user to enter a name and searches the town that person lives in.
Use the functions readPerson and searchTown
The function searchTown has 2 arguments:
- the array that needs to be searched
- a variable of the type Person that contains the name that needs to be searched. The town member
of that variable needs to be filled with the town found by the function searchTown.
Reading the name of the person you want to search for is done in the main function. Printing the
resulting town can also be done in the main function. If the name entered is not present in the array,
an appropriate message needs to be printed.
*/
/* HEADER FILES */
#include <stdio.h>
#include<ctype.h>
#include <string.h>
#include "task1.h"
/* readPerson: To read name and town from user */
/* Author: Gopisai
 * Created:29/9/2024
 * Modified:29/9/2024
*/
void readPerson(ST* s1) {
    int iIndex, iNum;
    char ch;
    /* Traversing loop To enetr data */
    for (iIndex = 0; iIndex < 3; iIndex++) {
        iNum = 0;
        printf("Enter name: ");

        while ((ch = getchar()) != '\n' && ch != EOF) {
            if (isalpha(ch)) {
                s1[iIndex].sName[iNum++] = ch;
            } else {
                printf("Enter valid characters for the name.\n");
                return;
            }
        }
        /* Null-terminate the name */
        s1[iIndex].sName[iNum] = '\0';



        printf("Enter City/Town: ");
        iNum = 0;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            s1[iIndex].sTown[iNum++] = ch;
        }
        /* Null-terminate the town */
        s1[iIndex].sTown[iNum] = '\0';


    
    }
   return;
}

/* searchTown : searching town of given person name */
char* searchTown(ST* s, char* str)
{
    for (int iIndex = 0; iIndex < 3; iIndex++) {
        if (strcmp(s[iIndex].sName, str) == 0) {
            return s[iIndex].sTown;
        }
    }
    return NULL;
}
/* End searchTown */
