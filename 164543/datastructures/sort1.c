/* sorting (bubble)
 * date:21/8/204
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void add_end(struct node ** );
void bubble_sort(struct node *,int);
void bubble_linksort(struct node *,int);
void display(struct node*);
int count(struct node*);
int main()
{
	int n;
	
struct node *p;//pointer to first node
p=NULL;
char ch;
	do{
	//add_begin(&hptr);
	add_end(&p);
	//add_middle(&hptr);
	printf("U want to continue to add a node(y/n)\n");
	scanf(" %c",&ch);
	}while((ch == 'y')||(ch == 'Y'));
display(p);
	n=count(p);
		printf("\n%d\n",n);
        //bubble_sort(p,n);
	bubble_linksort(p,n);
	display(p);

}
void bubble_sort(struct node*r,int n)
{
	int i,j,k,temp;
	struct node*p,*q;
	k=n;
	for(i=0;i<n-1;i++,k--)
	{
		p=r;
		q=p->link;
		for(j=1;j<k;j++)
		{
			if(p->data > q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			p=p->link;
			q=q->link;
		}
	}

}
void bubble_linksort(struct node*r,int n)
{
	int i,j,k;
	struct node*p,*temp,*q,*a;
	k=n;
	for(i=0;i<n-1;i++,k--)
	{
		a=p=r;
		q=p->link;
		for(j=1;j<k;j++)
		{
			if(p->data > q->data)
			{
				p->link=q->link;
				q->link=p;
				if(p!=r)
					a->link=q;
				else
					r=q;
				temp=p;
				p=q;
				q=temp;
			}
			p=p->link;
			q=q->link;
		}
	}

}
void add_end(struct node **q){
  struct node*temp;
  temp=(struct node*)malloc(sizeof(struct node));
  scanf("%d",&temp->data);

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

void display(struct node *q)
{
while(q!=NULL){
	printf("%d ",q->data);
	q=q->link;
}
}
int count (struct node *q)
{
	int count=0;
while(q!=NULL){
	count++;
	q=q->link;
}
return count;
}
