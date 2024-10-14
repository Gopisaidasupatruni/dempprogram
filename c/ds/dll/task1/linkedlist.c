#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/* Add a node at the end of the doubly linked list */
void d_append(ST **s, int num) {
    ST *temp, *r;
    temp = (ST *)malloc(sizeof(ST));
    temp->data = num;
    temp->link = NULL;
    if (*s == NULL) {
        temp->prv = NULL;
        *s = temp;
    } else {
        r = *s;
        while (r->link != NULL)
            r = r->link;
        r->link = temp;
        temp->prv = r;
    }
}

/* Add a node at the beginning of the doubly linked list */
void d_addatbegin(ST **s, int num) {
    ST *temp;
    temp = (ST *)malloc(sizeof(ST));
    temp->data = num;
    temp->prv = NULL;
    if (*s == NULL) {
        temp->link = NULL;
        *s = temp;
    } else {
        temp->link = *s;
        (*s)->prv = temp;
        *s = temp;
    }
}

/* Add a node after a specific number of nodes */
void d_addafter(ST **s, int loc, int num) {
    ST *temp, *q;
    int i;
    if (*s == NULL) {
        printf("List is empty\n");
        return;
    }
    q = *s;
    for (i = 1; i < loc && q != NULL; i++) {
        q = q->link;
    }
    if (q == NULL) {
        printf("There are less than %d elements in the list\n", loc);
        return;
    }
    temp = (ST *)malloc(sizeof(ST));
    temp->data = num;
    if (q->link != NULL) {
        temp->link = q->link;
        temp->prv = q;
        q->link->prv = temp;
        q->link = temp;
    } else {
        temp->link = NULL;
        temp->prv = q;
        q->link = temp;
    }
}

/* Display the contents of the doubly linked list */
void display(ST *q) {
    if (q == NULL) {
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
        count++;
        q = q->link;
    }
    return count;
}

/* Delete a node from the doubly linked list */
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
                                *s=(*s)->link;
				if (*s != NULL)
                                (*s)->prv=NULL;

                               free(q);
                        }
                        else if(q->link==NULL){
                                        q->prv->link=NULL;
					free(q);
			}
                                else{
                                q->prv->link=q->link;
                                q->link->prv=q->prv;


                                
                                free(q);
				}
                
                        return;
        }
                q=q->link;
        }
    printf("Node with data %d not found\n", num);
}

