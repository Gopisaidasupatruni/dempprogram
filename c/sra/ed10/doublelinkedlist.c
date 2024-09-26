/* This Program is to implement search function for doubly link list */
/* Author:Gopisai
 * Date  :24/9/2024
 */
/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<stdlib.h>/* for malloc() and free() */
/* structure */
typedef struct student
{
	struct student *prv;
	int data;
	struct student *next;
}ST;
/* FUNCTION PROTOTYPES */
void addNode(ST **pPtr);
void printData(ST *);
ST* searchNode(ST *, int );

int gCount=0;
/** MAIN PROGRAM */
/* main : To add and search nodes in doubly linked list */
int main()
{
	char cVar;
	 int iSearchKey;
        ST *headPtr = NULL;
        ST *foundNode;
	do
	{
		/* To add nodes */
		addNode(&headPtr);
		printf("do you want to add another data (y/n)?\n");
		scanf(" %c",&cVar);
	}while(cVar=='y'||cVar=='Y');
	/* To print nodes */
	printData(headPtr);
	 /* To search for a node */
    printf("Enter data to search: \n");
    scanf("%d", &iSearchKey);

    foundNode = searchNode(headPtr, iSearchKey);
    if (foundNode != NULL)
    {
        printf("Data %d found at node %d\n", foundNode->data,gCount);
    }
    else
    {
        printf("Data %d not found in the list.\n", iSearchKey);
    }
}
/* End main */
/* addNode: To enter a node in doubly linked list */
/* Author:Gopisai
 * Date  :24/9/2024
 */
void addNode(ST **pPtr)
{
	ST *ptemp;
	ptemp=(ST*)malloc(sizeof(ST));
	printf("Enter data: \n");
	scanf("%d",&ptemp->data);
	/* if there are no nodes*/
	if(*pPtr == 0) 
	{
		ptemp->prv = 0;
		ptemp->next = 0;
		*pPtr = ptemp;
	}
	else
	{
		ST *last = *pPtr;
		while(last -> next != 0)
			last = last -> next;

		ptemp -> prv = last;
		ptemp -> next = last->next;
		last->next = ptemp;
	}


}
/* End addNode */
/* printData: To print all nodes in list */
/* Author:Gopisai
 * Date  :24/9/2024
 */
void printData(ST *pPtr)
{
if(pPtr != 0) {
	printf("%d \n",pPtr->data);
	/* recursive call */
	printData(pPtr->next);
	}
}
/* End printData */
/* searchNode: To search a node in the list */
/* Author:Gopisai
 * Date  :24/9/2024
*/
ST* searchNode(ST *pPtr, int iElement )
{
	gCount=1;
	while(pPtr!=NULL)
	{
		/* checking if element is there or not */
		if(pPtr->data==iElement)
		{
			return pPtr;
		}
		++gCount;
		pPtr=pPtr->next;
	}
	return NULL;
}
/* End searchNode */
