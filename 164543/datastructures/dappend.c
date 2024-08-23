#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node*prv;
	int data;
	struct node*next;
};
void append(struct node**,int num);
void display(struct node*);
int main()
{
struct node*p;
p=NULL;
append(&p,10);
append(&p,20);
append(&p,30);
display(p);
}

void append(struct node**q,int num){

	struct node*temp,*last;
	temp=*q;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	if(*q==NULL)
	{
		temp->next=NULL;
		*q=temp;
		temp->prv=NULL;
	}
	else
	{
		last=*q;
		while(last->next!=NULL)
			last=last->next;
		temp->next=last->next;
		last->next=temp;
		temp->prv=last;
	}
}
void display(struct node*q){
	while(q!=0)
	{
		printf("%d ",q->data);
		q=q->next;
	}
}
