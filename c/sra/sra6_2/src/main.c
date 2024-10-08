/* Required header files */
#include <stdio.h>
#include "task1.h"
/*MAIN PROGRAM */
/* main: To write content into file */
int main()
{

	int inum,iIndex;
	/* Number of person */
	printf("enter a number\n");
	scanf("%d",&inum);
	ST s1[inum];
	/* File opening in appending mode */
	FILE*fp=fopen("file","a+");
	/* Traversing through loop to enter data */
	for(iIndex=0;iIndex<inum;iIndex++)
	{

		printf("enter name: ");
		scanf(" %[^\n]",s1[iIndex].sName);
		printf("enter Age: ");
		scanf("%d",&s1[iIndex].iAge);

		printf("enter salary: ");
		scanf("%f",&s1[iIndex].fSalary);
		/* printing data into file */
		fprintf(fp, "%s %d  %f\n",s1[iIndex].sName,s1[iIndex].iAge,s1[iIndex].fSalary);

	}
	/* closing file */
	fclose(fp);
	return 0;
}
/* End main */
