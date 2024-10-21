/* Implement the task P1, P2 , P3

 

 

P1. Write a C program to implement this Doubly Linked List (DLL). First declare a structure representing a node of the doubly linked list.

    struct dnode{

      struct dnode *prev;

      int data;

      struct dnode  *next;

      }

You can have the following function prototypes to implement this. 

 

adds a new node at the end of the doubly linked list


d_append(struct dnode **s, int num)

 



d_addatbeg(struct dnode **s, int num)

 

 

d_addafter(struct dnode *q, int loc, int num) //loc is not equal to 0

 

 

d_display (struct dnode *q)

 
 

d_count (struct dnode *q)

 

 

d_delete(struct dnode **s, int num)

 

P2. In the same project, create one source file main.c.  In main.c you should have the following codes to test your implementation. 

Initialize an empty doubly linked list pointed by p;

 

Call d_append() function to add elements at the end of the doubly linked list (DLL) ;

 

d_display (p); 

 

printf ("\n No. of Elements in the DLL: %d\n", d_count(p));

 

Call d_addatbeg() function to add elements at the beginning of the DLL;

 

d_display (p); 

 

printf ("\n No. of Elements in the DLL: %d\n", d_count(p));

 

Call d_addafter() function to add elements after the specified number of nodes in the DLL;

 

d_display (p); 

 

printf ("\n No. of Elements in the DLL: %d\n", d_count(p));

 

Call d_delete() function to delete elements from the DLL;

 

d_display (p); 

 

printf ("\n No. of Elements in the DLL after deletion: %d\n", d_count(p));
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

/* MAIN PROGRAM */
int main() {
	/* head pointer */
    ST *p = NULL;
   
   
    int iData, idel, num, index;
    char choice;
/* Printing Instructions */
    while (1) {
        printf("\n--- Linked List Operations Menu ---\n");
        printf("a. Add at beginning of p\n");
        printf("i. Append at end\n");
        printf("d. Display list\n");
        printf("c. Count list\n");
        printf("r. Delete a number\n");
        printf("s. add after \n");
        printf("q. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
		/* To add begin to p*/
            case 'a':
                printf("Enter data to p add at the beginning: ");
                scanf("%d", &iData);
                d_addatbegin(&p, iData);
                break;
		/* To add end*/
            case 'i':
                printf("Enter data to append: ");
                scanf("%d", &iData);
                d_append(&p, iData);
                break;

		/* To push node*/
            case 'd':
                printf("Linked list elements: ");
                display(p);
                printf("\n");
                break;
            case 'r':
                printf("Enter number to delete: ");
                scanf("%d", &idel);
                d_delete(&p, idel);
                break;
		/* To exit */
	    case 'c':
		printf("Elements count\n");
		int icount=d_length(p);
		printf("Total elements %d\n",icount);
		break;
		/* add after */
	    case 's':
                printf("Enter data to add after: ");
                scanf("%d", &iData);
		int n;
		printf("Enter number to add after a node :");
		scanf("%d",&n);
		printf("Adding node after %d node\n",n);
	        d_addafter(&p,n,iData);	
		break;
		/* exit */
            case 'q':
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
/* End main */
