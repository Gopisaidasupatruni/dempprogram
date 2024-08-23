#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void push(struct node**,int);
int pop(struct node**);
void display(struct node*);
int main(){
struct node*top;
int i;
top=NULL;
push(&top,1);
push(&top,2);
display(top);
i=pop(&top);
printf("popped %d\n",i);
display(top);
}

void push(struct node**q,int num){
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	temp->link=*q;
	*q=temp;

}
int pop(struct node**q){
int i;
struct node*temp;
if(*q==NULL)
	printf("stack is empty\n");
else
{
	temp=*q;
	i=temp->data;
	*q=temp->link;
		free(temp);
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
