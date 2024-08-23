#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prv;
	int data;
	struct node *next;
};
void append(struct node **,int );
void add_begin(struct node **,int );
void display(struct node*);
int main()
{
struct node *p;//pointer to first node
p=NULL;
append(&p,10);
append(&p,20);
add_begin(&p,30);
display(p);
}
void add_begin(struct node**q,int num){
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	if(*q==NULL){
          temp->next=*q;
	  *q=temp;
	  temp->prv=*q;
	}
	else
	{
		(*q)->prv=temp;
		temp->next=*q;
		*q=temp;
		temp->prv=NULL;
	}


}
void append(struct node**q,int num){
struct node*temp,*r;
temp=*q;//*q is p
if(*q==NULL)
{
	temp=(struct node*)malloc(sizeof(struct node));
		temp->data=num;
	        temp->next=NULL;
		*q=temp;//p point to node
}
else
{
	temp=*q;//temp point to first node
	while(temp->next!=NULL)
		temp=temp->next;

	r=(struct node*)malloc(sizeof(struct node));
	r->data=num;
	r->next=NULL;
	temp->next=r;//connecting last node to temp
}
}
void display(struct node *q)
{
while(q!=NULL){
	printf("%d ",q->data);
	q=q->next;
}
}
