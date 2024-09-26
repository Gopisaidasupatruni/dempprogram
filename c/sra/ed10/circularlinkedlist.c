/* This Program is to do a circular linked list, the next pointer of the last node points to the starting 
node of the list. Write a recursive C function that prints the elements of a circular 
linked list of integers in the reverse order (that is, from end to beginning). 
Use the following function prototype: 
void printCList ( clist l, const clist h ); 
Here the second parameter points to the beginning of the list and is kept constant 
across the calls. Assume that no dummy header node is used in the circular linked list.
*/
/* Author:Gopisai
 * Date  :24/9/2024
 */
/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<stdlib.h>/* for malloc()  */

/* structure */
typedef struct student
{
	int data;
	struct student *next;
}ST;
/* FUNCTION PROTOTYPES */
void addNode(ST **,ST **);
void printData(ST *);
void printCList(ST *, const ST*);

/** MAIN PROGRAM */
/* main : To add and print nodes in reverse of circular linked list */
int main()
{
	char cVar;
	/* Initializing nodes */ 
        ST *frontPtr = NULL;
        ST *rearPtr=NULL;
	do
	{
		/* To add nodes */
		addNode(&frontPtr,&rearPtr);
		printf("do you want to add another data (y/n)?\n");
		scanf(" %c",&cVar);
	}while(cVar=='y'||cVar=='Y');
	/* To print nodes */
	printData(frontPtr);
	    /* To print nodes in reverse order */
    printf("Elements in reverse order:\n");
    if (frontPtr != NULL) /* Only print if list is not empty */
        printCList(frontPtr, frontPtr);
    
	 
}
/* End main */
/* addNode: To enter a node in doubly linked list */
/* Author:Gopisai
 * Date  :24/9/2024
 */
void addNode(ST **pFront,ST **pRear)
{
	ST *ptemp;
	ptemp=(ST*)malloc(sizeof(ST));
	printf("Enter data: \n");
	scanf("%d",&ptemp->data);
	ptemp->next=NULL;
	/* if there are no nodes*/
	if(*pFront == 0) 
	{
		*pFront=ptemp;
	}
	else
	(*pRear)->next=ptemp;
		*pRear=ptemp;
		(*pRear)->next=*pFront;


}
/* End addNode */
/* printData: To print all nodes in list */
/* Author:Gopisai
 * Date  :24/9/2024
 */
void printData(ST *pPtr)
{
	ST *pVar=pPtr,*pVar1=NULL;
	/* To print all data */
	while(pVar!=pVar1)
	{
	printf("%d \n",pVar->data);
	pVar=pVar->next;
	pVar1=pPtr;
	}
}
/* End printData */
/* printCList: To print the circular linked list in reverse order */
/* Author: Gopisai
 * Date  : 24/9/2024
 */
void printCList(ST *l, const ST *h)
{

if( l->next != h)
	printCList(l->next,h);

printf("%d \n",l->data);
}
/* End printCList */
