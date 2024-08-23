#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node*prv;
	int data;
	struct node *next;
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

add_after(&p,1,30);
add_after(&p,3,40);

display(p);
}
void add_after(struct node**q,int loc,int num){
	struct node *temp,*r;
	int i;
	temp=*q;
	for(i=1;i<loc&&temp!=NULL;i++){
		temp=temp->next;
	}
		if(temp==NULL)
		{
			printf("less elements\n");
			
		}
		else{
	
	
      
	r=(struct node*)malloc(sizeof(struct node));
	r->data=num;
	r->next=temp->next;
	r->prv=temp;
	if(r->next!=NULL)
		r->next->prv=r;
	temp->next=r;
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
		*q=temp;
		temp->prv=NULL;//p point to node
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
