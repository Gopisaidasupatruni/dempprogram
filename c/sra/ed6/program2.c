/* This program is to extend task#1 that further reads name, age and salary of a chosen number of people and stores 
   that information into a file. All data of 1 person is stored in a structure. Once the data of 1 person is 
   2
   read, the structure containing that data is written to a file at once. Afterwards, the data of the next 
   person is read, … Make sure the names can contain spaces!
   */
/* Author: Gopisai
 * Created: 17/9/2024
 * Modified: 17/9/2024
 */
/* REQUIRED HEADER FILES */
#include<stdio.h>

/* MACRO DEFINITIONS */
#define LENGTH 100
/* Structure with name age salary members */
typedef struct person
{
	char sName[LENGTH];
	int iAge;
	float fSalary;
}ST;
/* MAIN PROGRAM */
/* main: To store data name age and salary in a file */
int main()
{
	char sStr[LENGTH];
	int inum,iIndex;
	printf("enter a number\n");
	scanf("%d",&inum);
	ST s1[inum];
	FILE*fp=fopen("file","a+");
	for(iIndex=0;iIndex<inum;iIndex++)
	{

		printf("enter name: ");	
		scanf(" %[^\n]",s1[iIndex].sName);
		printf("enter Age: ");	
		scanf("%d",&s1[iIndex].iAge);

		printf("enter salary: ");	
		scanf("%f",&s1[iIndex].fSalary);
		fprintf(fp,"%s %d  %f\n",s1[iIndex].sName,s1[iIndex].iAge,s1[iIndex].fSalary);
	}
}
