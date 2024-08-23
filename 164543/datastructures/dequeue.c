#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void addqatend(struct node**,struct node**,int);
void addqatbeg(struct node**,struct node**,int);
int delqatend(struct node**,struct node**);
int delqatbeg(struct node**,struct node**);
void display(struct node*);
int main(){
struct node *front,*rear;
int i;
front=NULL;
rear=NULL;
addqatbeg(&front,&rear,3);
addqatbeg(&front,&rear,4);
addqatend(&front,&rear,1);
addqatend(&front,&rear,2);
display(front);
printf("\n");
i=delqatend(&front,&rear);
printf("popped %d\n",i);
display(front);
printf("\n");
i=delqatbeg(&front,&rear);
printf("popped %d\n",i);
display(front);
}

void addqatend(struct node**front,struct node**rear,int num){
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	temp->link=NULL;
	if(*front==NULL)
		*front=temp;
	else
		(*rear)->link=temp;
	*rear=temp;

}
void addqatbeg(struct node**front,struct node**rear,int num){
	struct node*temp;
	int *p;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	temp->link=NULL;
	if(*front==NULL)
		*front=*rear=temp;
	else
	{
		temp->link=*front;
		*rear=*front;
		*front=temp;
	}

}
int delqatbeg(struct node**front,struct node**rear){
int i;
struct node*temp;
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
int delqatend(struct node**front,struct node**rear){
int i;
struct node*temp,*q,*r;
temp=*front;
if(*rear==NULL)
	printf("queue is empty\n");
else
{
	while(temp!=*rear){

		r=temp;
		temp=temp->link;
	}
	q=*rear;
	i=q->data;
	free(q);
	*rear=r;
	(*rear)->link=NULL;
		
		if(*rear==NULL)
			*front=NULL;
	return i;
}
}
void display(struct node*q){
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->link;
	}
}
