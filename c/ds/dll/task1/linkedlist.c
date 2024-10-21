/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


/* Add a node at the end of the doubly linked list */
/*
 * Author: Gopisai
 * Date: 18/10/2024
*/
void d_append(ST **s, int num) {
    ST *temp, *r;
    /* Allocate memory for the new node */
    temp = (ST *)malloc(sizeof(ST));
    temp->data = num;
    temp->link = NULL;
    if (*s == NULL) {
	    /* If list is empty, previous is NULL */
        temp->prv = NULL;
	/* Set the new node as the head */
        *s = temp;
    } else {
        r = *s;
	 /* Traverse to the last node */
        while (r->link != NULL)
            r = r->link;
	 /* Link the new node at the end */
        r->link = temp;
        temp->prv = r;
    }
}

/* Add a node at the beginning of the doubly linked list */
/*
 * Author: Gopisai
 * Date: 18/10/2024
*/
void d_addatbegin(ST **s, int num) {
    ST *temp;
    /* Allocate memory for the new node */
    temp = (ST *)malloc(sizeof(ST));
    temp->data = num;
    temp->prv = NULL;
    if (*s == NULL) {
	    /* Set link to NULL if list is empty */
        temp->link = NULL;
        *s = temp;
    } else {
	    /* Set link to the current head */
        temp->link = *s;
        (*s)->prv = temp;
	 /* Make new node the head */
        *s = temp;
    }
}

/* Add a node after a specific number of nodes */
/*
 * Author: Gopisai
 * Date: 18/10/2024
*/
void d_addafter(ST **s, int loc, int num) {
    ST *temp, *q;
    int i;
    if (*s == NULL) {
	     /* If list is empty, exit */
        printf("List is empty\n");
        return;
    }
    q = *s;
    for (i = 1; i < loc && q != NULL; i++) {
        q = q->link;/* Traverse the list until location */
    }
    if (q == NULL) {
        printf("There are less than %d elements in the list\n", loc);
        return;
    }
    /* Allocate memory for the new node */
    temp = (ST *)malloc(sizeof(ST));
    temp->data = num;
    if (q->link != NULL) {
	    /* Set the link to the next node */
        temp->link = q->link;
	 /* Set previous to the current node */
        temp->prv = q;
	 /* Update the previous pointer of the next node */
        q->link->prv = temp;
	  /* Link the new node after the current node */
        q->link = temp;
    } else {
	     /* If it's the last node, link is NULL */
        temp->link = NULL;
        temp->prv = q;
        q->link = temp;
    }
}

/* Display the contents of the doubly linked list */
/*
 * Author: Gopisai
 * Date: 18/10/2024
*/
void display(ST *q) {
    if (q == NULL) {
	     /* If list is empty, print message */
        printf("List is empty\n");
        return;
    }
    while (q != NULL) {
        printf("%d ", q->data);
        q = q->link;
    }
    printf("\n");
}

/* Count the number of nodes in the doubly linked list */
int d_length(ST *q) {
    int count = 0;
    while (q != NULL) {
        count++; /* Increment count for each node */
        q = q->link;
    }
    return count;
}

/* Delete a node from the doubly linked list */
/*
 * Author: Gopisai
 * Date: 18/10/2024
*/
void d_delete(ST **s, int num) {
    ST *q = *s;
    if ( q== NULL) {
        printf("List is empty\n");
        return;
    }
      while(q!=NULL)
        {
		if(q->data==num)
		{
                        if(q==*s)
                        {
				  /* Update head if node to delete is the first node */
                                *s=(*s)->link;
				if (*s != NULL)
                                (*s)->prv=NULL;

                               free(q);
                        }
                        else if(q->link==NULL){
				/* If it's the last node, update link of the previous node */
                                        q->prv->link=NULL;
					free(q);
			}
                                else{
					/* Update the link of the previous node */
                                q->prv->link=q->link;
				/* Update the previous pointer of the next node */
                                q->link->prv=q->prv;


                                
                                free(q);
				}
                
                        return;
        }
                q=q->link;
        }
    printf("Node with data %d not found\n", num);
}
/* End */
