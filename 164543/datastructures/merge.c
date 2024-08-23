/* merging of linked lists
 * Author:Gopi
 * date: 20/8/2024
 */
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*link;
};
void add_begin(struct node **,int );
void display(struct node*);
int count (struct node*);
void merge(struct node*,struct node*,struct node**);
int main()
{
	struct node *first,*second,*third;
	third=second=first=NULL;
        int c1=0,c2=0;
	add_begin(&first,20);
	add_begin(&first,10);
	display(first);
	c1=count(first);
	printf("\ncount  %d\n",c1);
	add_begin(&second,10);
	add_begin(&second,30);
	add_begin(&second,15);
	display(second);
	c2=count(second);
	printf("\ncount  %d\n",c2);
	printf("after merging\n");
	merge(first,second,&third);
	display(third);
	c2=count(third);
	printf("\ncount  %d\n",c2);
}

void merge(struct node*first,struct node*second,struct node**q){
if(first==NULL&&second==NULL)
	return;
struct node *z;
z=NULL;
while(first!=NULL && second !=NULL)
{
	if(*q==NULL)
	{
		*q=(struct node*)malloc(sizeof(struct node));
		z=*q;
	}
	else
	{
		z->link=(struct node*)malloc(sizeof(struct node));
		z=z->link;
	}
	if(first->data < second->data)
	{
		z->data=first->data;
		first=first->link;
        }
	else
	{
		if(second->data < first->data)
		{
			z->data=second->data;
			second=second->link;
		}
		else
		{
			if(first->data==second->data)
			{
				z->data=second->data;
                                first=first->link;
				second=second->link;
			}
		}
	}
}

while(first!=NULL)
{

		z->link=(struct node*)malloc(sizeof(struct node));
		z=z->link;
		z->data=first->data;
		first=first->link;
}
while(second!=NULL)
{

		z->link=(struct node*)malloc(sizeof(struct node));
		z=z->link;
		z->data=second->data;
		second=second->link;
}
		z->link=NULL;
		}
		
void add_begin(struct node **q,int num){
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    if(*q==NULL||(*q)->data>num)

    {
    temp->link=*q;
    *q=temp;
    }
    else
    {
	    struct node*last=*q;
	    while(last!=0)
	    {
		    if(last->data<=num &&(last->link==NULL||last->link->data>num)){

	    temp->link=last->link;
	    last->link=temp;
	    return;
}
last=last->link;
}
temp->link=NULL;
last->link=temp;
}
}
void display(struct node*q){
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->link;
	}
}
int count (struct node*q)
{
	int count=0;
	while(q!=NULL)
	{
		count++;
		q=q->link;
	}
	return count;
}
