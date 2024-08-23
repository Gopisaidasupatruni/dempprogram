// prog for Binary Search Tree

#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
	struct st *left;
	int num;
	struct st *right;
}TREE;

void add_tree(TREE **ptr,int n);
void pre_order(TREE *ptr);
void in_order(TREE *ptr);
void post_order(TREE *ptr);
void delete(TREE **ptr,int num);
int main()
{
	TREE *hptr = 0; int n,num;  char ch;

	do{
	printf("Enter the number\n");
	scanf("%d",&n);

	add_tree(&hptr,n);
	printf("Do you want to continue...(y/n)\n");
	scanf(" %c",&ch);
	}while((ch == 'y') || (ch == 'Y'));

	printf("pre-order\n");
	pre_order(hptr);
	printf("\n");
	printf("in-order\n");
	in_order(hptr);
	printf("\n");
	printf("post-order\n");
	post_order(hptr);
	printf("\n");
}

void add_tree(TREE **ptr,int n)
{
	if(*ptr == 0){
	*ptr = (TREE *)malloc(sizeof(TREE));
	(*ptr) -> num = n;
	(*ptr) -> left = (*ptr) -> right = 0;
	}
	else if( (*ptr)->num < n)
	add_tree(&(*ptr)->right,n);
	else
	add_tree(&(*ptr)->left,n);
}
void pre_order(TREE *ptr)
{
	if(ptr){
	printf("%d-->",ptr -> num);
	pre_order(ptr->left);
	pre_order(ptr->right);
	}
}
void in_order(TREE *ptr)
{
	if(ptr){
	in_order(ptr->left);
	printf("%d-->",ptr -> num);
	in_order(ptr->right);
	}
}
void post_order(TREE *ptr)
{
	if(ptr){
	post_order(ptr->left);
	post_order(ptr->right);
	printf("%d-->",ptr -> num);
	}
}
