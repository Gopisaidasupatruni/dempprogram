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
void selection_sort(struct node *,int);
void selection_linksort(struct node *,int);
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
        //selection_sort(p,n);
	selection_linksort(p,n);
	display(p);

}
void selection_sort(struct node*r,int n)
{
	int i,j,k,temp;
	struct node*p=r,*q;
	
	for(i=0;i<n-1;i++)
	{
		
		q=p->link;
		for(j=i+1;j<n;j++)
		{
			if(p->data > q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			
			q=q->link;
		}
		
		p=p->link;
	}

}
void selection_linksort(struct node*r,int n)
{
	int i,j,k;
	struct node*p=r,*temp,*q,*a=r;
	
	for(i=0;i<n-1;i++)
	{
		
		q=p->link;
		for(j=i+1;j<n;j++)
		{
			if(p->data > q->data)
			{
				if(p!=r)
					a->link=q;
				else
					r=q;
				p->link=q->link;
				q->link=p;
				temp=p;
				p=q;
				q=temp;
			}
			
			q=q->link;
		}
		a=p;
		p=p->link;
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
printf("\n");
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
