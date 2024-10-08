#ifndef CALC_H
#define CALC_H

/* MACRO DEFINITIONS */
#define LENGTH 100

/* Structure containing name and town */
typedef struct person
{
    char sName[LENGTH];
    int iAge;
    float fSalary;
}ST;


void test_readPerson(void);
#endif /* CALC_H */

