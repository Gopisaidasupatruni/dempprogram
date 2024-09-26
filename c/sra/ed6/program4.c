/* This program is to Search the age and wages of a person based upon a name entered by the user
*/
/* Author: Gopisai
 * Created: 17/9/2024
 * Modified: 17/9/2024
 */
/* REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
/* MACRO DEFINITIONS */
#define LENGTH 100
/* Structure with name age salary members */
struct person
{
        char sName[LENGTH];
        int iAge;
        float fSalary;
};
/* MAIN PROGRAM */
/* main: To search age and wages of person based on name  */

int main()
{
	char sStr[LENGTH];
	int inum,iIndex;
	printf("enter a number\n");
        scanf("%d",&inum);
	struct person s1[inum];
	/* Opening file in write mode */
	FILE*fp=fopen("file","w");
	for(iIndex=0;iIndex<inum;iIndex++)
	{

	printf(" Enter name age salary of %d:\n",iIndex+1);
	scanf("%s %d %f",s1[iIndex].sName,&s1[iIndex].iAge,&s1[iIndex].fSalary);
	fprintf(fp,"%s %d %f",s1[iIndex].sName,s1[iIndex].iAge,s1[iIndex].fSalary);
	}
	fclose(fp);
	printf("enter name\n");
	scanf("%s",sStr);
	for(iIndex=0;iIndex<inum;iIndex++)
	{
             if(strcmp(s1[iIndex].sName,sStr)==0)
		     printf("name: %s\n Age: %d\n Salary: %.2f\n",s1[iIndex].sName,s1[iIndex].iAge,s1[iIndex].fSalary);
	}
	
	
}
	
