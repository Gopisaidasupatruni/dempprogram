#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node*next;
};
void add(struct node**);
void print(struct node *);
int countoccurance(struct node*,int);
int main()
{
struct node *hptr=0;
char ch;
do{

add(&hptr);
printf("do you want to add another\n");
scanf(" %c",&ch);
}while(ch=='y');
print(hptr);
int n=countoccurance(hptr,1);
printf("count %d\n",n);
}
int countoccurance(struct node* list,int n)
{
	int count=0;
	while(list!=NULL){
	if(list->value==n)
		count++;
	list=list->next;
	}
	return count;
}

void add(struct node**ptr)
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&temp->value);
	temp->next=*ptr;
	*ptr=temp;
}
void print(struct node*ptr)
{
	while(ptr!=0)
	{
		printf("%d\n",ptr->value);
		ptr=ptr->next;
	}
}

