//circular queue
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void addq(struct node**,struct node**,int);
int delq(struct node**,struct node**);
void display(struct node*);
int main(){
struct node *front,*rear;
int i;
front=NULL;
rear=NULL;
addq(&front,&rear,1);
addq(&front,&rear,2);
addq(&front,&rear,3);
addq(&front,&rear,4);
display(front);
i=delq(&front,&rear);
printf("popped %d\n",i);
i=delq(&front,&rear);
printf("popped %d\n",i);
display(front);
}

void addq(struct node**front,struct node**rear,int num){
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	temp->link=NULL;
	if(*front==NULL)
		*front=temp;
	else
		(*rear)->link=temp;
	*rear=temp;
	(*rear)->link=*front;

}
int delq(struct node**front,struct node**rear){
int i;
struct node*temp;
if(*front==NULL)
	printf("queue is empty\n");
else
{
	if(*front==*rear)
	{
		i=(*front)->data;
		free(*front);
		*front=NULL;
		*rear=NULL;
	}
	else
	{
	temp=*front;
	i=temp->data;
	*front=(*front)->link;
	(*rear)->link=*front;
		free(temp);
		}
	return i;
}
}
void display(struct node*f){
         struct node*q=f,*p=NULL;
	while(q!=p)
	{
		printf("%d ",q->data);
		q=q->link;
		p=f;
	}
}
