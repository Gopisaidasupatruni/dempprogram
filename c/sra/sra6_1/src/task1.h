#ifndef CALC_H
#define CALC_H

/* MACRO DEFINITIONS */
#define LENGTH 100

/* Structure containing name and town */
typedef struct person
{
    char sName[LENGTH];
    char sTown[LENGTH];
}ST;

/* FUNCTION PROTOTYPES */
void readPerson(ST*);
char* searchTown(ST*, char*);

#endif /* CALC_H */

