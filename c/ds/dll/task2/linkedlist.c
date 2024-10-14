/** This program is to write dll has cll */
/**REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/* append: To add nodes at the end */
void d_append(ST **q, int num) {
    ST *temp = *q, *r;
        temp = (ST *)malloc(sizeof(ST));
        temp->data = num;
    if (*q == NULL) {
	/* adding at beginning */
        temp->link = temp;
	temp->prv=temp;
        *q = temp;
    }
   /* if atleast one node */ 
    else {
	    /* Traversing upto end */
	    r=*q;
        while (r->link != *q) {
            r = r ->link;
        }
	/* add end */
	
	r->link=temp;
	temp->prv=r;
       temp->link=*q;
       (*q)->prv=temp;
    }
}
/* End append */
/* display: To display all elements */
void display(ST *q) {
    ST *temp = q;
    if(q==NULL)
    {
	    printf("list is empty\n ");
	    return;
    }
    /* Traversing through all nodes */
    do
    {
	    printf("%d ",temp->data);
	    temp=temp->link;
    }while(temp!=q);
}

/* add_begin: To add a node at the beginning */
void d_addatbegin(ST **ptr, int iNum) {
	/* Adding nodes at beggining */
	ST *q=*ptr;
    ST *temp = (ST *)malloc(sizeof(ST));
    temp->data = iNum;
    if(*ptr==NULL)
    {
    temp->link = temp;
    temp->prv=temp;
    *ptr = temp;
    }
    else
    {
	    while(q->link!=*ptr)
		    q=q->link;

	    temp->link = *ptr;
	    temp->prv=q;
	    q->link=temp;
	    (*ptr)->prv = temp;
	    *ptr=temp;
	    
	    
    }
}


/* Length : count all nodes */
int d_length(ST *head) {
    int count = 1;
    ST *current = head->link;
    while (current != head) {
	    /* To count all nodes */
        count++;
        current = current->link;
    }
    return count;
}

