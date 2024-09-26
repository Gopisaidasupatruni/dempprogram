/*Write a program that allows to build and adapt an alphabetically ordered single-linked list with a 
command interpreter. Part of the code is written below. Only the missing functions need to be 
programmed.*/
/*  Author: Gopisai
 *  Date:19/9/2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h> /* needed for strcpy() and strcmp() */
#include <stdlib.h> /* needed for malloc(), free() */

#define STRLEN 64

/* structure Node */
typedef struct node {
    char name[STRLEN];
    struct node *next;
} Node;

/* FUNCTION PROTOTYPES */
void showHelp(void);
void add(char*,Node **);
void removeElement(char *, Node **);
int isItem(char *, Node *);
int countItems(Node *);
void removeList(Node **);
void showList(Node *);
char *trim(char *);

/* MAIN PROGRAM */
/* main: To perform a single linked list operations 
 * adding node in sorted manner
 * deleting and searching a node
 * counting and printing number of nodes 
*/
int main(void) {
    char instruction[STRLEN];
    Node *p_head = NULL;
    char *pi; /* pi = pointer to the instruction */

    printf("Test program for a single-linked list.\n");
    printf("\nEnter an instruction (h = help)\n");
    printf("\n> ");
    memset(instruction, '\0', STRLEN);

    fgets(instruction, STRLEN, stdin); 
    pi = trim(instruction);

    while (*pi != 'q') {
        switch (*pi) {
		/* To add node */
            case 'i':
                add( trim(pi+1),&p_head);
                break;
		/* To remove element */
            case 'd':
                removeElement(trim(pi + 1), &p_head);
                break;
		/* To search element */
            case 'f':
                if (isItem(trim(pi + 1), p_head)) {
                    printf("\"%s\" is in the list.\n", trim(pi + 1));
                } else {
                    printf("\"%s\" is NOT in the list.\n", trim(pi + 1));
                }
                break;
		/* To show all elements */
            case 'l':
                showList(p_head);
                break;
		/* To count items */
            case 'n':
                printf("Number of list items: %d\n", countItems(p_head));
                break;
		/* To remove a element */
            case 'r':
                removeList(&p_head);
                break;
		/* To print instructions */
            case 'h':
                showHelp();
                break; 
		/* To exit */
            case 'q':
                break;
	    /*case '\n':
		break;*/
            default:
                printf("Unknown instruction (h = help)\n");
        }
        printf("\n> ");
        memset(instruction, '\0', STRLEN);
        fgets(instruction, STRLEN, stdin); 
        pi = trim(instruction);
    }

    removeList(&p_head);
    return 0;
}
/* showHelp: shows menu by pressing h */
void showHelp(void) {
    printf("i <string> : inserts the element in <string> alphabetically into the list\n");
    printf("d <string> : removes the element in <string> from the list\n");
    printf("f <string> : searches the list and returns if the string is in the list or not\n");
    printf("l : shows the full list\n");
    printf("n : returns the number of items in the list\n");
    printf("r : removes the full list\n");
    printf("h : shows the help menu (this list)\n");
    printf("q : end of the program (first remove the list)\n");
}
/* add: To add a node in a single linked list */
void add( char*s,Node **b) {
    //printf("This function inserts \"%s\" (alphabetically) into the list\n", s);
Node*temp,*r;

        temp=(Node*)malloc(sizeof(Node));
         strcpy(temp->name,s);
if(*b==NULL||strcmp((*b)->name,temp->name)>0)
{
	temp->next=*b;
	*b=temp;
}
else
{
	r=*b;
        while(r!=NULL)
             {
/* if it is not a head node */
if((strcmp(r->name,temp->name)<0)&&(r->next==NULL||(strcmp(r->next->name,temp->name)>0))){
	temp->next=r->next;
	r->next=temp;
	return;
	     }
r=r->next;
}
}
}

/* removeElement: To remove a element from the list */
void removeElement(char *s, Node **b) {
    //printf("This function removes \"%s\" from the list\n", s);
Node *prv=NULL,*temp;

        temp=*b;
	
        while(temp!=NULL)
        {

                if(strcmp(s,temp->name)==0)
                {
			/* if it is a first node */
                        if(temp==*b)
                        {
                                *b=temp->next;
                                free(temp);
                                return;
                        }
                        else
                        {
                                prv->next=temp->next;
				/* free : to free the memory */
                                        free(temp);
                                return;
                        }
                }
                else
                {
                        prv=temp;
                        temp=temp->next;
                }
        }
	printf("not found");
}
/* isItem: Tosearch a element */
int isItem(char *s, Node *b) {
//    printf("This function searches \"%s\" in the list\n", s);
    while (b != NULL) {
        if (strcmp(s, b->name) == 0) {
            // The item was found in the list
            return 1;
        }
        b = b->next;
    }
    // The item was not found in the list
    return 0;
}

/*countItems: To count number of nodes */

int countItems(Node *b) {
   // printf("This function returns the number of items in the list\n");
	    int count=0;
    if (b == NULL) {
        printf("The list is EMPTY\n");
    } else {
        printf("count:\n");
        while (b != NULL) {
            count++;
            b = b->next;
        }
    }
    printf("\n\n");
    return count;
}
/* removeList: To remove a element from the list */
void removeList(Node **b) {
    Node *p = *b;
    while (p != NULL) {
        *b = p->next;
        free(p);
        p = *b;
    }
}
/* showList: To print all nodes avaliable in list */
void showList(Node *b) {
    if (b == NULL) {
        printf("The list is EMPTY\n");
    } else {
        printf("The list:\n");
        while (b != NULL) {
            printf("%s ", b->name);
            b = b->next;
        }
    }
    printf("\n\n");
}
/* trim: to remove spaces */
char *trim(char *s) {
    while (*s == ' ') s++;
    return s;
}

