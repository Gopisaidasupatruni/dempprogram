/* This program reads the data from the file written in the Task#2 . */
/* Author: Gopisai
 * Created: 17/9/2024
 * Modified: 17/9/2024
 */
/* REQUIRED HEADER FILES */
#include<stdio.h>

/* Structure to hold name, age, and salary */
struct person {
    char name[20];
    int age;
    float salary;
};

/* MAIN PROGRAM */
/*main: To open a file in read mode to read data from file*/
int main() {
    int inum, iIndex;
    
    printf("Enter the number of persons:\n");
    scanf("%d", &inum);

    struct person s1[inum];

    // Open file for writing
    FILE *fp = fopen("file3", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    // Input and write data to file
    for (iIndex = 0; iIndex < inum; iIndex++) {
        printf("Enter name, age, and salary for person %d:\n", iIndex + 1);
        scanf("%s %d %f", s1[iIndex].name, &s1[iIndex].age, &s1[iIndex].salary);
        fprintf(fp, "%s %d %.2f\n", s1[iIndex].name, s1[iIndex].age, s1[iIndex].salary);
    }

    fclose(fp);

    /* Open file for reading */
    fp = fopen("file3", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    /* Read and display data */
    printf("\nData from file:\n");
    while (fscanf(fp, "%s %d %f", s1[0].name, &s1[0].age, &s1[0].salary) != EOF) {
        printf("name: %s\nage: %d\nsalary: %.2f\n", s1[0].name, s1[0].age, s1[0].salary);
    }

    fclose(fp);
    return 0;
}

