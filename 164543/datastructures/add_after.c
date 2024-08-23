#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void append(struct node **,int );
void add_after(struct node **,int,int );
void display(struct node*);
int main()
{
struct node *p;//pointer to first node
p=NULL;
append(&p,10);
append(&p,20);

add_after(&p,2,30);
display(p);
}
void add_after(struct node**q,int loc,int num){
	struct node *temp,*r;
	int i;
	temp=*q;
	for(i=1;i<loc&&temp!=NULL;i++){
		temp=temp->link;
	}
		if(temp==NULL)
		{
			printf("less elements\n");
			
		}
		else{
	
	r=(struct node*)malloc(sizeof(struct node));
	r->data=num;
	r->link=temp->link;
	temp->link=r;
		}
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
