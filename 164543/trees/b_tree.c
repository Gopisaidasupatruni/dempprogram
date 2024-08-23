/* implementing a binary tree
 * 22/8/2024
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct binarytreenode
{
	struct binarytreenode *left;
	int data;
	struct binarytreenode *right;

}BT;
void in_sert(BT**,int);
void in_order(BT*);
void pre_order(BT*);
void post_order(BT*);
int main()
{
	BT*bt = 0; int n,num;  char ch;

	do{
	printf("Enter the number\n");
	scanf("%d",&n);

	in_sert(&bt,n);
	printf("Do you want to continue...(y/n)\n");
	scanf(" %c",&ch);
	}while((ch == 'y') || (ch == 'Y'));

	
	printf("in-order\n");
	in_order(bt);
	printf("\n");
	printf("pre-order\n");
	pre_order(bt);
	printf("\n");
	printf("post-order\n");
	post_order(bt);
	printf("\n");
}
void in_sert(BT**q,int num){
 if(*q==NULL)
 {
	*q=(BT*)malloc(sizeof(BT));
         
	(*q)->left=NULL;
	(*q)->data=num;
	(*q)->right=NULL;
	return;
}
else
{
	if(num<(*q)->data)
	in_sert(&(*q)->left,num);	
	else 
	in_sert(&(*q)->right,num);
}
}
void in_order(BT *ptr)
{	
	if(ptr){
	in_order(ptr->left);
	printf("%d-->",ptr -> data);
	in_order(ptr->right);
	}
}

void pre_order(BT *ptr)
{	
	if(ptr){
	printf("%d-->",ptr -> data);
	pre_order(ptr->left);
	pre_order(ptr->right);
	}
}

void post_order(BT *ptr)
{	
	if(ptr){
	post_order(ptr->left);
	post_order(ptr->right);
	printf("%d-->",ptr -> data);
	}
}
