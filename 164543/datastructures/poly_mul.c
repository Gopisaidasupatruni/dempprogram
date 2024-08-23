/* merging of linked lists
 * Author:Gopi
 * date: 21/8/2024
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
void mul(struct node*,struct node*,struct node**);
int count (struct node*);
void padd(float,int,struct node**);
void addition(struct node*,struct node*,struct node**);
int main()
{
	struct node *first,*second,*total;
	total=second=first=NULL;
        //int c1=0,c2=0;
	add_begin(&first,2,2);
	add_begin(&first,3,1);
	add_begin(&first,4,0);
	display(first);
	
	
	add_begin(&second,1,1);
	add_begin(&second,5,0);
	
	display(second);
       printf("multiplying\n");
       mul(first,second,&total);
       display(total);
       
	
}

void mul(struct node*first,struct node*second,struct node**q){

if(first==NULL&&second==NULL)
	return;
struct node *z;
float coeff1;
int exp1;
z=second;

while(first!=NULL )
{
	while(second!=NULL)
	{
		coeff1=first->coeff*second->coeff;
		exp1=first->exp+second->exp;
		second=second->link;
		padd(coeff1,exp1,q);
	}
	second=z;
	first=first->link;
}
}
void padd(float coeff, int exp, struct node **q) {
    struct node *r, *temp = *q;
    
    if (*q == NULL || exp > (*q)->exp) {
        // Insert at the beginning of the list
        r = (struct node*)malloc(sizeof(struct node));
        r->coeff = coeff;
        r->exp = exp;
        r->link = *q;
        *q = r;
    } else {
	       // Traverse the list to find the correct position or combine terms
        while (temp != NULL) {
            if (temp->exp == exp) {
                // Combine the coefficients if the exponent matches
                temp->coeff += coeff;
                return;
            }
            if (temp->link == NULL || temp->link->exp < exp) {
                // Insert the new node in the correct position
                r = (struct node*)malloc(sizeof(struct node));
                r->coeff = coeff;
                r->exp = exp;
                r->link = temp->link;
                temp->link = r;
                return;
            }
            temp = temp->link;
        }
    }
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
