/*Task#2:
Write a program with command line arguments that calculates the age (in number of years) of a 
number of people based upon their date of birth and the current date.
- make a text file containing a number of names with their corresponding dates of birth. Make sure 
names and dates of birth are always written in the same way in the text file.
- write a function “read_person” to read the data of 1 person from the file and save that data into a 
struct of the type “Person”. This struct contains a name field and a field to save the date of birth,
which is a struct of the type “Date”.
- call the program from the command line with the current date and the text file as arguments
- write a function “calculate” that calculates the age of a person in years, months and days. This 
function also determines which person is the oldest and which person has the longest name.
- printing the ages is done in the main function. Print also the names of the oldest person and of the 
person with the longest name.
age_calc ages.txt 01 12 2014
the ages are:
Wilbur is 18 years old
Tom is 18 years old
Sarah is 15 years old
Tom is the oldest of the 3 persons in the file.
The person with the longest name is: Wilbur*/
/* Author: Gopisai
 * Created: 18/9/2024
 * modified:19/9/2024
*/
/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/** MACRO DEFINITIONS */
#define LENGTH 100
/* structure to store date */

struct Date {
    int day;
    int month;
    int year;
};

struct Person {
    char name[LENGTH];
    struct Date birthdate;
};
/* FUNCTION PROTOTYPES */
void readPerson(struct Person*, char*);
void calculate(struct Person*,struct Date);
/*MAIN PROGRAM */
/*main: determines which person is oldest and person with longest name */
int main(int argc, char* argv[]) {
    if (argc != 5) {
        return 1;
    }
       struct Date current_date;
    current_date.day = atoi(argv[2]);
    current_date.month = atoi(argv[3]);
    current_date.year = atoi(argv[4]);

    struct Person p[10];
    readPerson(p, argv[1]); 
    calculate(p,current_date);
    /* Pass the filename to readPerson */
}
/*readPerson: To read three persons data */
/* Author: Gopisai
 * Created: 18/9/2024
 * modified:19/9/2024
*/
void readPerson(struct Person *p, char *filename) {
    FILE *fp = fopen(filename, "r"); 
    /* Use argv[1] as the filename */

    if (fp == NULL) {
        printf("file doesnt exist.\n");
        return;
    }

    for (int i = 0; i < 3; i++) { 
	    
        fscanf(fp, "%s %d %d %d", p[i].name, &p[i].birthdate.day, &p[i].birthdate.month, &p[i].birthdate.year);
        printf("%s %02d-%02d-%d\n", p[i].name, p[i].birthdate.day, p[i].birthdate.month, p[i].birthdate.year);
    }

    fclose(fp);
}
/* calculate : It calculates the longest name and oldest age */
/* Author: Gopisai
 * Created: 18/9/2024
 * modified:19/9/2024
*/
void calculate(struct Person *p, struct Date d) {
    int age[3], age_months[3],age_days[3],ioldestAge = 0, ioldestIndex = 0,inameIndex=0;
    char slongname[LENGTH];
    int iIndex;

    /* Calculate the age of each person and print it */
    for (iIndex = 0; iIndex < 3; iIndex++) {
 age_months[iIndex] = d.month - p[iIndex].birthdate.month;
        age_days[iIndex]= d.day - p[iIndex].birthdate.day;     
     	age[iIndex] = d.year - p[iIndex].birthdate.year;
        printf("%s age is %d\n", p[iIndex].name, age[iIndex]);

        
        if (age[iIndex] > ioldestAge) {
            ioldestAge = age[iIndex];
            ioldestIndex = iIndex;
        }
        if (strlen(p[iIndex].name) > strlen(slongname)) {
            
            inameIndex=iIndex;
        }
    }

    /* Prints the oldest person's name and age */
    printf("The oldest person is %s, age %d\n", p[ioldestIndex].name, ioldestAge);
    printf("The large name is %s \n", p[inameIndex].name);
}
/* End calculate */
