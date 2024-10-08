/* This program adds last names to the existing data and writes it to a new file. */
/* Author: Gopisai
 * Created: 18/9/2024
 * Modified: 18/9/2024
 */

/* REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>

/* MACRO DEFINITIONS */
#define LENGTH 200
/* Structure to hold name, last name, age, and salary */
typedef struct person {
    char firstname[LENGTH];
    char lastname[LENGTH];
    int age;
    float salary;
}ST;



/* MAIN PROGRAM */
/* main : Adds the last name into existing data */
int main() {
    int iIndex;
    ST s1[3];

    /* Open the file with the original data */
    FILE *fp = fopen("file", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    /* Read the existing data (first name, age, and salary) */
  for (iIndex = 0; iIndex < 3; iIndex++) {
        fscanf(fp, "%s %d %f", s1[iIndex].firstname, &s1[iIndex].age, &s1[iIndex].salary);
    }
    fclose(fp);
    

    /* Read the last names for each person */
    for (iIndex = 0; iIndex < 3; iIndex++) {

        printf("Enter the last name %s: ", s1[iIndex].firstname);
        scanf("%s", s1[iIndex].lastname);
    }

    /* Open a new file to write the updated data (first name, last name, age, salary) */
    fp = fopen("file", "w");
    

    /* Write the updated data to the new file */
    for (iIndex = 0; iIndex < 3; iIndex++) {
        fprintf(fp, "name: %s\nlast name: %s\nage: %d\nsalary: %.2f\n\n",
                s1[iIndex].firstname, s1[iIndex].lastname, s1[iIndex].age, s1[iIndex].salary);
    }
    fclose(fp);

    /* Print the updated data to the screen */
    printf("\nThe following data was entered:\n");
    for (iIndex = 0; iIndex < 3; iIndex++) {
        printf("name: %s\nlast name: %s\nage: %d\nsalary: %.2f\n\n",
               s1[iIndex].firstname, s1[iIndex].lastname, s1[iIndex].age, s1[iIndex].salary);
    }

    return 0;
}
/* End main */
