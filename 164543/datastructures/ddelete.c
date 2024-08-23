#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prv;
	int data;
	struct node *next;
};
void delete(struct node**,int);
void append(struct node **,int );
void display(struct node*);
int main()
{
struct node *p;//pointer to first node
p=NULL;
append(&p,10);
append(&p,20);
display(p);
printf("\n");
delete(&p,20);
display(p);
}

void delete(struct node**s,int num){
	struct node*q=*s;
	while(q!=NULL)
	{
		if(q->data==num)
		{
			if(q==*s)
			{
				*s=(*s)->next;
				(*s)->prv=NULL;
				
		               free(q);	
			}
			else
			{
				if(q->next==NULL)
					q->prv->next=NULL;
				else{
				q->prv->next=q->next;
				q->next->prv=q->prv;

				
				}
				free(q);
		}
			return;
	}
		q=q->next;
	}
		printf("element not found\n");
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
		temp->prv=NULL;
}
else
{
	temp=*q;//temp point to first node
	while(temp->next!=NULL)
		temp=temp->next;

	r=(struct node*)malloc(sizeof(struct node));
	r->data=num;
	r->next=NULL;
	r->prv=temp;
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
