/*This program is to add each Person also street, number, postal code and state information in file
*/
/* Author:Gopisai
 * Created:18/9/2024
 * Modified:18/9/2024
 */
/** REQUIRED HEADER FILES*/
#include<stdio.h>
#include<string.h>
/* MACRO DEFINITIONS */
#define MAX 100
/*structure*/
struct person
{
	char name[MAX];
	char lastname[MAX];
	char town[MAX];
	char street[MAX];
	int number;
	int code;
	char state[MAX];
};
/* FUNCTION PROTOTYPES */
void readperson(struct person*);
/* MAIN PROGRAM */
/*main: To add each person data */
int main()
{
	char sStr[20];
	int iIndex;
	struct person s1[3];
	readperson(s1);
	/* Opening a file in write mode */
	FILE*fp=fopen("file6","w");
	for(iIndex=0;iIndex<3;iIndex++)
	{
			
	fprintf(fp,"%s %s %s %s %d %d %s\n",s1[iIndex].name,s1[iIndex].lastname,s1[iIndex].town,s1[iIndex].street,s1[iIndex].number,s1[iIndex].code,s1[iIndex].state);

}
}
/* End main() */
/* readperson: To add street number,postalcode and state */
/* Author:Gopisai
 * Created:18/9/2024
 * Modified:18/9/2024
 */
void readperson(struct person*s1)
{
	int ivar;
	for(ivar=0;ivar<3;ivar++){
	printf(" Enter name and town of person %d\n",ivar+1);
		scanf("%s %s",s1[ivar].name,s1[ivar].town);
	}
	for(ivar=0;ivar<3;ivar++)
	{
		printf("enter the last name of %s\n",s1[ivar].name);
		scanf("%s",s1[ivar].lastname);
		printf("enter the street name of %s\n",s1[ivar].name);
		scanf("%s",s1[ivar].street);
		printf("enter the number of %s\n",s1[ivar].name);
		scanf("%d",&s1[ivar].number);
		printf("enter the postal code of %s\n",s1[ivar].name);
		scanf("%d",&s1[ivar].code);
		printf("enter the state of %s\n",s1[ivar].name);
		scanf("%s",s1[ivar].state);
	}
}
/*End of readperson */
