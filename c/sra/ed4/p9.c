#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node*next;
};
void add(struct node**);
void print(struct node *);
void re_move(struct node**);
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
re_move(&hptr);
print(hptr);
}
void re_move(struct node** list)
{
/*	struct node*p=(*list)->next;
	(*list)->next=p->next;
	free(p);*/
	/*struct node*temp=*list;
	temp=temp->next;
	(*list)->next=temp->next;
	free(temp);*/
	struct node*temp=(*list)->next;
	(*list)->next=temp->next;
	free(temp);
	
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

