#include <stdio.h>
#include <string.h>
#include "functions.h"

void readPerson(Person *s1) {
    for (int i = 0; i < NUM_PEOPLE; i++) {
        printf("Enter name  hometown age salary of person %d: ", i + 1);
        scanf(" %[^\n]%*c", s1[i].sName);  // Read name with spaces
        scanf(" %[^\n]%*c", s1[i].sTown); 
        scanf( " %d", &s1[i].iAge);
        scanf(" %f", &s1[i].fSalary);	// Read town with spaces
    }
}

char *searchTown(Person *s, char *name) {
    for (int i = 0; i < NUM_PEOPLE; i++) {
        if (strcmp(s[i].sName, name) == 0) {
            return s[i].sTown;
        }
    }
    return NULL;
}

void savePersonToFile(Person *s1, FILE *fp) {
    for (int i = 0; i < NUM_PEOPLE; i++) {
        fprintf(fp, "Name: %s\n", s1[i].sName);
        fprintf(fp, "Town: %s\n", s1[i].sTown);
        fprintf(fp, "Age: %d\n", s1[i].iAge);
        fprintf(fp, "Salary: %.2f\n\n", s1[i].fSalary);
    }
}

void readPersonFromFile(FILE *fp) {
    Person p;
    while (fscanf(fp, "%s %s %d %f", p.sName, p.sTown, &p.iAge, &p.fSalary) != EOF) {
        printf("Name: %s, Town: %s, Age: %d, Salary: %.2f\n", p.sName, p.sTown, p.iAge, p.fSalary);
    }
}

void addAdditionalInfo(Person *s1) {
    for (int i = 0; i < NUM_PEOPLE; i++) {
        printf("Enter last name for %s: ", s1[i].sName);
        scanf(" %[^\n]%*c", s1[i].sLastName);
        printf("Enter street name: ");
        scanf(" %[^\n]%*c", s1[i].sStreet);
        printf("Enter house number: ");
        scanf("%d", &s1[i].iNumber);
        printf("Enter postal code: ");
        scanf("%d", &s1[i].iPostalCode);
        printf("Enter state: ");
        scanf(" %[^\n]%*c", s1[i].sState);
    }
}

void saveExtendedInfoToFile(Person *s1, FILE *fp) {
    for (int i = 0; i < NUM_PEOPLE; i++) {
        fprintf(fp, "Name: %s\nLast Name: %s\nTown: %s\nStreet: %s\nNumber: %d\nPostal Code: %d\nState: %s\n\n",
                s1[i].sName, s1[i].sLastName, s1[i].sTown, s1[i].sStreet, s1[i].iNumber, s1[i].iPostalCode, s1[i].sState);
    }
}

