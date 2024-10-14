#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
}ST;

void enQueue(ST**,ST**,int);
int deQueue(ST**,ST**);
void display(ST*);
int main()
{
	ST *front,*rear;
        front=rear=NULL;	
	int n;char ch;
	do
	{
		printf("Enter data \n");
		scanf("%d", &n);
	enQueue(&front ,&rear, n);
	printf("do you want to add another node ? (y/n)\n");
	scanf(" %c",&ch);
	}while(ch=='y');
	display(front );
	printf("\n");
	int ivar=deQueue(&front,&rear);
	display(front);


}
/* End main */
void enQueue(ST** front,ST** rear,int num)
{
        ST*temp;
        temp=(ST*)malloc(sizeof(ST));
        temp->data=num;
        temp->link=NULL;
	if(*front==NULL)
		*front = temp;
	else
		(*rear)->link = temp;
	*rear=temp;
}
int deQueue(ST **front,ST **rear)
{
	int i;
	ST *temp;
	if(*front==NULL)
		printf("queue is empty\n");
	else
	{
		temp=*front;
		i=temp->data;
		*front=temp->link;
		free(temp);
		if(*front==NULL)
			*rear=NULL;
		return i;
	}
}

void display(ST *q)
{
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->link;
	}

}
