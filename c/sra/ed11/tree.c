/* Nodes Under the Subtree
   You are given a binary tree rooted at a node, say node number 1. For each node x in this tree, 
   you have to print the number of nodes in the subtree rooted at x (note that the subtree also 
   contains the node x).
Input: The first line contains single integer n(1 <= n <=10000) the number of nodes in the tree.
The nodes in the tree are numbered from 1 to n. The root of the tree will be node 1.
The next n lines have two numbers separated by a space. The number x y in line i (one of these
n lines) denotes the left and right child of node i in the tree respectively. For example, for the ith node, we may have the following:
1. 5 3
This implies that the left child of node i is 5 and the right child is 3.
2. 0 3
This implies that node i has no left child but its right child is 3.
3. 0 0
This implies that node i has no left or right child.
Output: Let ai denote the number of nodes in the subtree rooted at node i. Then the
output is the sequence
a1 a2 . . . an separated by a
space. 
Input : 3
2 3
0 0
0 0
Output : 3 1 1
Explanation: In this tree, the root node 1 has one left child, that is node 2, and one right child, 
that is node 3. Node 2 and Node 3 have no children. Thus, the number of nodes in the subtree 
of node 1 is 3. The number of nodes in the subtree of node 2 and node 3 is 1 */
/* Author: Gopisai
 * Date: 25/9/2024
 */
/* REQUIRED HEADER FILES */
#include<stdio.h>
#include<stdlib.h>
/* structure */
typedef struct tree 
{
	struct tree*left;
	int iData;
	struct tree *right;

}TREE;


/* FUNCTION PROTOTYPES */
void addTree(TREE**,int);
void preOrder(TREE*);
int countNodes(TREE*,int*);
/* MAIN PROGRAM */
/* main: To count number of nodes under subtree */
int main()
{
	TREE * pHptr=NULL;
	int iNumber;
	char cCharacter;
	do
	{
		printf("enter data\n");
		scanf("%d",&iNumber);
		addTree(&pHptr,iNumber);
		printf("do you want to add another node (y/n)\n");
		scanf(" %c",&cCharacter);
	}while(cCharacter=='y');
	preOrder(pHptr);
	printf("\n");
	int subtree[100];
	countNodes(pHptr,subtree);
	for (int iIndex = 1; iIndex < 100; iIndex++) {
		if (subtree[iIndex] > 0) {
			printf("%d ", subtree[iIndex]);
		}
	}

}
/* end main*/
/* countNodes: To count number of nodes under subtree */
/* Author: Gopisai
 * Date: 25/9/2024
 */
int countNodes(TREE*pPtr,int*subtree)
{
	if(pPtr==NULL){
		return 0;
	}
	int ileft=countNodes(pPtr->left,subtree);
	int iright=countNodes(pPtr->right,subtree);
	int total=1+ileft+iright;
	subtree[pPtr->iData]=total;
	return total;

}
/* addTree: To add nodes*/
/* Author: Gopisai
 * Date: 25/9/2024
 */
void addTree(TREE**pPtr,int iNum)
{
	/*if there are no nodes */
	if(*pPtr==NULL)
	{
		*pPtr=(TREE*)malloc(sizeof(TREE));
		(*pPtr)->iData=iNum;
		(*pPtr)->left=(*pPtr)->right=NULL;
	}
	else if((*pPtr)->iData <= iNum && iNum!=0)
		addTree(&(*pPtr)->right,iNum);

	else if((*pPtr)->iData > iNum && iNum!=0)
		addTree(&(*pPtr)->left,iNum);
}
/*preOrder: To print nodes in preorder */
/* Author: Gopisai
 * Date: 25/9/2024
 */
void preOrder(TREE *pPtr)
{
	if(pPtr!=NULL)
	{
		printf("%d ",pPtr->iData);
		preOrder(pPtr->left);
		preOrder(pPtr->right);
	}
}
/* end preOrder */
