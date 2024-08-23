#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
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
delete(&p,10);
display(p);
}

void delete(struct node**q,int num){
	struct node*old,*temp;
	temp=*q;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			if(temp==*q)
			{
				*q=temp->link;
				free(temp);
				return;
			}
			else
			{
				old->link=temp->link;
				free(temp);
				return;
			}
		}
		else
		{
			old=temp;
			temp=temp->link;
		}
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
