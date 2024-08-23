/* merging of linked lists
 * Author:Gopi
 * date: 20/8/2024
 */
#include<stdio.h>
#include<stdlib.h>

struct node
{
	float coeff;
	int exp;
	struct node*link;
};
void add_begin(struct node **,float, int );
void display(struct node*);
int count (struct node*);
void addition(struct node*,struct node*,struct node**);
int main()
{
	struct node *first,*second,*total;
	total=second=first=NULL;
        //int c1=0,c2=0;
	add_begin(&first,2.5,2);
	add_begin(&first,1.4,1);
	add_begin(&first,3,3);
	display(first);
	
	
	add_begin(&second,1.4,1);
	add_begin(&second,1.0,0);
	add_begin(&second,4,4);
	display(second);
       
	printf("\nafter adding\n");
	addition(first,second,&total);
	display(total);
	
}

void addition(struct node*first,struct node*second,struct node**q){
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
	if(first->exp < second->exp)
	{
		z->coeff=second->coeff;
		z->exp=second->exp;
		second=second->link;
        }
	else
	{
		if(first->exp > second->exp)
		{
		z->coeff=first->coeff;
		z->exp=first->exp;
		first=first->link;
		}
		else
		{
			if(first->exp==second->exp)
			{
				z->coeff=first->coeff+second->coeff;
                                z->exp=first->exp;
				first=first->link;
				second=second->link;
			}
		}
	}
}

while(first!=NULL)
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

		z->coeff=first->coeff;
		z->exp=first->exp;
		first=first->link;
}
while(second!=NULL)
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
		z->coeff=second->coeff;
		z->exp=second->exp;

		second=second->link;
}
		z->link=NULL;
		}
		
/*void add_begin(struct node **q,float x,int y){
    struct node*temp;
    temp=*q;
 
    if(*q==NULL)

    {
    *q=(struct node*)malloc(sizeof(struct node));
    temp=*q;
    }
    else
    {
	    while(temp->link!=NULL)
		    temp=temp->link;

    temp->link=(struct node*)malloc(sizeof(struct node));
	    temp=temp->link;
}
temp->coeff=x;
temp->exp=y;
temp->link=NULL;

}
*/

void add_begin(struct node **q,float x,int y){
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->coeff=x;
    temp->exp=y;
    if(*q==NULL||(*q)->exp<y)

    {
    temp->link=*q;
    *q=temp;
    }
    else
    {
	    struct node*last=*q;
	    while(last!=0)
	    {
		    if(last->exp>=y &&(last->link==NULL||last->link->exp<y)){

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
		printf("%.1fx^%d ",q->coeff,q->exp);
		q=q->link;
	}
	printf("\n");
}

