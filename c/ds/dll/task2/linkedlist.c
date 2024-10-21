/** This program is to write dll has cll */
/* doubly linked list as circular linked list */
/**REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/* append: To add nodes at the end */
/*
 * Author: Gopisai
 * Date : 18/10/2024 
*/
void d_append(ST **q, int num) {
    ST *temp = *q, *r;
    /* Allocate memory for the new node */
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
	/* Last node link points to new node */
	r->link=temp;
	/* New node previous points to last node */
	temp->prv=r;
	/* New node link points to the head */
       temp->link=*q;
        /* Head's previous points to new node */
       (*q)->prv=temp;
    }
}
/* End append */
/* display: To display all elements */
/*
 * Author: Gopisai
 * Date : 18/10/2024 
*/
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
/*
 * Author: Gopisai
 * Date : 18/10/2024 
*/
void d_addatbegin(ST **ptr, int iNum) {
	/* Adding nodes at beggining */
	ST *q=*ptr;
    ST *temp = (ST *)malloc(sizeof(ST));
    temp->data = iNum;
    /* Adding node when list is empty */
    if(*ptr==NULL)
    {
    temp->link = temp;
    temp->prv=temp;
    *ptr = temp;
    }
    /* Traverse to the last node */
    else
    {
	    while(q->link!=*ptr)
		    q=q->link;
           /* New node's link points to the current head */
	    temp->link = *ptr;
	    /* New node's previous points to the last node */
	    temp->prv=q;
	    /* Last node's link points to the new node */
	    q->link=temp;
	    /* Update current head's previous to new node */
	    (*ptr)->prv = temp;
	    /* Set new node as the head */
	    *ptr=temp;
	    
	    
    }
}


/* Length : count all nodes */
/*
 * Author: Gopisai
 * Date : 18/10/2024 
*/
int d_length(ST *head) {
    int count = 1;
    ST *current = head->link;
    while (current != head) {
	    /* To count all nodes */
        count++;
	/* Increment count for each node */
        current = current->link;
    }
    /* Return total count */
    return count;
}

