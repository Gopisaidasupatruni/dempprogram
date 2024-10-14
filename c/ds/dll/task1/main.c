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
	    case 's':
                printf("Enter data to append: ");
                scanf("%d", &iData);
		int n;
		printf("Enter number to add after a node :");
		scanf("%d",&n);
		printf("Adding node after %d node\n",n);
	        d_addafter(&p,n,iData);	
		break;
            case 'q':
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
/* End main */
