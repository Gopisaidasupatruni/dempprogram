#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void append(struct node **,int );
void add_end(struct node **,int );
void display(struct node*);
int main()
{
struct node *p;//pointer to first node
p=NULL;
append(&p,10);
append(&p,20);
add_end(&p,30);
display(p);
}
void add_end(struct node **q,int num){
  struct node*temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=num;

	if(*q == 0) {
	temp->link = *q;
	*q = temp;
	}
	else {
	struct node *last = *q; //last = *p

	while(last->link != 0)
      last = last->link;//incrementing last ptr upto the last node

	temp->link = last->link;
	last->link = temp;
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
