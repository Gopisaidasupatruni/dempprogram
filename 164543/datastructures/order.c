#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void append(struct node **,int );
void delete(struct node **,int );
void display(struct node*);
int count(struct node*);
int main()
{
struct node *p;//pointer to first node
p=NULL;
append(&p,10);
append(&p,5);
append(&p,20);
display(p);
delete(&p,10);
display(p);
int n=count(p);
printf("count:%d",n);
}
void delete(struct node **q,int num){
	struct node *prv,*temp;
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
				prv->link=temp->link;
					free(temp);
				return;
			}
		}
		else
		{
			prv=temp;
			temp=temp->link;
		}
	}
	printf("not found");
}
void append(struct node**q,int num){
struct node*temp,*last=*q;//*q is p

	temp=(struct node*)malloc(sizeof(struct node));
		temp->data=num;
		if(*q==NULL||(*q)->data>num){
	        *q=temp;//p point to node
		(*q)->link=last;
}
else
{
	while(last!=NULL)
	{
		if(last->data<=num &&(last->link==NULL||last->link->data>num))
		{
			temp->link=last->link;
			last->link=temp;
			return;
		}
		last=last->link;
	}
}
}

void display(struct node *q)
{
while(q!=NULL){
	printf("%d ",q->data);
	q=q->link;
}
}
int count(struct node *q)
{
	int c=0; 
while(q!=NULL){
	c++;
	q=q->link;
}
return c;
}
