#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define LENGTH 100
#define NUM_PEOPLE 3

typedef struct person {
    char sName[LENGTH];
    char sTown[LENGTH];
    char sLastName[LENGTH];
    char sStreet[LENGTH];
    int iNumber;
    int iPostalCode;
    char sState[LENGTH];
    int iAge;
    float fSalary;
} Person;

void readPerson(Person *s1);
char *searchTown(Person *s, char *name);
void savePersonToFile(Person *s1, FILE *fp);
void readPersonFromFile(FILE *fp);
void addAdditionalInfo(Person *s1);
void saveExtendedInfoToFile(Person *s1, FILE *fp);

#endif

