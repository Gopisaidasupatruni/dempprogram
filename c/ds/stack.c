/* REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
/*STRUCTURE */
typedef struct node {
    int data;
    struct node *link;
} ST;
/** FUNCTION PROTOTYPES */
void display(ST *);
void push(ST **, int);
void pop(ST **);
int itemTop(ST **);
int toppop(ST **);
void clear(ST *);
int isEmpty(ST *ptr) ;

/*MAIN PROGRAM */
/* main: Performing stack operations */
int main() {
    ST *p = NULL;
    int iData, idel, num, index;
    char choice;

    while (1) {
        printf("\n--- Stack Operations Menu ---\n");
        printf("p. Pushing element\n");
        printf("r. Pop an element \n");
        printf("d. Display list\n");
        printf("t. top element\n");
        printf("n. top element also to remove it\n");
	printf("i. isempty To check stack is empty\n");
        printf("c. Clear the stack\n");
        printf("q. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
             /* Push */
            case 'p':
                printf("push data: \n");
                scanf("%d", &iData);
                push(&p,iData);
                break;
            /* Pop */
            case 'r':
                printf("popped data \n");
                pop(&p);
                break;
            /* display */
            case 'd':
                printf("Stack list elements: ");
                display(p);
                printf("\n");
                break;
           /* displaying Top element */
            case 't':
                printf("top item: ");

                int num = itemTop(&p);
                printf("%d\n",num);
                break;
            /* top and pop */
            case 'n':
                printf("printing top item and removing: ");

                int inum=toppop(&p);
                printf("%d\n",inum);
		
                break;
            /* checking stack is empty or not */
	    case 'i':
                if (isEmpty(p))
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            /* To clear stack */
            case 'c':
                clear(p);
		p=NULL;
                printf("stack is empty\n");
            /* exit */
            case 'q':
                printf("Exiting program...\n");
                return 0;  

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
/* End main */

/* display: To display all elements */
void display(ST *q) 
{
    ST *temp = q;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
}


/* push: To add a node  */
void push(ST **ptr, int iNum) {
	
    ST *temp = (ST *)malloc(sizeof(ST));
    temp->data = iNum;
    temp->link = *ptr;
    *ptr = temp;
}
/* pop: to remove a node */
void pop(ST**ptr)
{
    if(*ptr==NULL){
	    printf("No elements to pop\n");
            return ;
    }
    ST*temp = *ptr;
    *ptr=temp->link;
    free(temp);

}
/* clear: To clear the stack */
void clear(ST*ptr)
{
	ST*temp;
	while(ptr!=NULL)
	{
		temp=ptr;
		ptr=ptr->link;
		free(temp);
	}

}
/* isEmpty: To check if the stack is empty */
int isEmpty(ST *ptr) {
    return ptr == NULL;
}

/* toppop: To print top element and pop it*/
int toppop(ST **ptr) 
{
	if(*ptr==NULL)
	{
		printf("no data\n");
		return 0;
	}
	
    int top=(*ptr)->data;
    pop(ptr);
    return top;
}
/* itemTop: To print top element in stack */
int itemTop(ST **ptr) {
	if(*ptr==NULL)
	{
		printf("no data\n");
		return 0;
	}
	
    ST *temp = *ptr;
 
    return temp->data;
}
/* End itemTop */
