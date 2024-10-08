/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
#include<ctype.h>

/* MACRO DEFINITIONS */
#define LENGTH 100

/* Structure containing name and town */
typedef struct person {
    char sName[LENGTH];
    char sTown[LENGTH];
} ST;

/** FUNCTION PROTOTYPES */
void readPerson(ST*);
char* searchTown(ST*, char*);

/** MAIN PROGRAM */
/* main: Printing town of person
 * Reading the name of the person you want to search
 */
int main() {
    char sStr[LENGTH], cVariable;
    ST s1[3];
    int iIndex = 0;

    /* To Read data */
    readPerson(s1);

    getchar();  // To clear the buffer
    printf("Enter a name to search: ");
    
    while ((cVariable = getchar()) != EOF && cVariable != '\n') {
        sStr[iIndex++] = cVariable;
    }
    
    /* Null terminating */
    sStr[iIndex] = '\0';

    char* pResult = searchTown(s1, sStr);

    if (pResult != NULL) {
        printf("This person lives in %s.\n", pResult);
    } else {
        printf("Person not found.\n");
    }

    return 0;
}

/* readPerson: To read name and town from user */
void readPerson(ST* s1) {
    int iIndex, iNum;
    char ch;

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
}

/* searchTown: To search town of a person */
char* searchTown(ST* s, char* str) {
    int iIndex;

    for (iIndex = 0; iIndex < 3; iIndex++) {
        /* Comparing the given string with stored names */
        if (strcmp(s[iIndex].sName, str) == 0) {
            return s[iIndex].sTown;
        }
    }
    /* If name is not found */
    return NULL;
}

