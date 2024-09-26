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
/* Author: Gopisai
 * Created:17/9/2024
 * Modified:17/9/2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h> 
/*To include strcmp*/

/* MACRO DEFINITIONS */
#define LENGTH 100

/* Structure containing name and town */
struct person
{
	char sName[LENGTH];
	char sTown[LENGTH];
};
/** FUNCTION PROTOTYPES */
void readPerson(struct person*);
char * searchTown(struct person*,char*);
/** MAIN PROGRAM */
/* main: Printing town of person
 * Reading the name of the person you want to search 
 */
int main()
{
	char sStr[LENGTH],cVariable;
	struct person s1[3];
	int iIndex=0;
	/* To Read data */
	readPerson(s1);
	getchar();
	printf("enter a name to search\n");
	while((cVariable=getchar())!=EOF && cVariable !='\n')
		sStr[iIndex++]=cVariable;
	/* Null terminating */
	 sStr[iIndex]='\0';

	char *pResult=searchTown(s1,sStr);

        printf("This person lives in %s \n",pResult);

}
/* End main */
/* readPerson: To read name and town from user */
/* Author: Gopisai
 * Created:17/9/2024
 * Modified:17/9/2024
*/
void readPerson(struct person*s1)
{
	int iIndex;

	for(iIndex=0;iIndex<3;iIndex++){
		printf("Enter name: ");
		
		scanf(" %[^\n]",s1[iIndex].sName);
		printf("Enter City/Town: ");
		scanf(" %[^\n]",s1[iIndex].sTown);
	}

}
/* End readPerson */
/* searchTown: To search town of a person */
/* Author: Gopisai
 * Created:17/9/2024
 * Modified:17/9/2024
 */
char * searchTown(struct person* s,char* str)
{
int iIndex;

for(iIndex=0;iIndex<3;iIndex++)
{
	if(strcmp(s[iIndex].sName,str)==0)
	{
		return s[iIndex].sTown;
	}
}
/* If name is not found */
printf("not found\n");
}
/* End searchTown */
