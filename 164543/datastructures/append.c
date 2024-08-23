#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void append(struct node **,int );
void display(struct node*);
int main()
{
struct node *p;//pointer to first node
p=NULL;
append(&p,10);
append(&p,20);
display(p);
}
void append(struct node**q,int num){
struct node*temp,*r;
temp=*q;//*q is p
if(*q==NULL)
{
	temp=(struct node*)malloc(sizeof(struct node));
		temp->data=num;
	        temp->link=NULL;
		*q=temp;//p point to node
}
else
{
	temp=*q;//temp point to first node
	while(temp->link!=NULL)
		temp=temp->link;

	r=(struct node*)malloc(sizeof(struct node));
	r->data=num;
	r->link=NULL;
	temp->link=r;//connecting last node to temp
}
}
void display(struct node *q)
{
while(q!=NULL){
	printf("%d ",q->data);
	q=q->link;
}
}
