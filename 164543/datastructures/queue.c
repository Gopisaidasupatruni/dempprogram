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
display(front);
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

}
int delq(struct node**front,struct node**rear){
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
void display(struct node*q){
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->link;
	}
}
