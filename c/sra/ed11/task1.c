/*At the EIC Cafeteria, n employees are standing in the queue. Today, on the menu, we have 
either a plain dosa or a masala dosa. Each employee has a preference. He/She either want to
eat a sada dosa or a masala dosa. At the front end of the queue, there is a stack of dosas, a 
mix of sada and masala dosas. A employee at the front of the queue performs the following 
operation
1. If the employee likes a sada dosa and the top of the stack is a sada dosa, then the 
employee takes the sada dosa and leaves the queue.
2. If the employee likes a masala dosa and the top of the stack is a masala dosa, then the
employee takes the masala dosa and leaves the queue.
3. Else the employee leaves the front of the queue and goes to end of the queue.
This process goes on till no one in the queue is able to leave it. All these employees will not 
be able to have the breakfast today. Your job is to find the number of such employees.
Input: In the input O(zero) will be used to represent a sada dosa and 1(one) represents a 
masala dosa. The first line of the input contains single integer n(1 ≤ n ≤ 10000), the number
of employees in the queue as well as the number of dosas on the stack. The next line 
contains n integers (only 1 and 0) separated by a space. This sequence represents the stack 
where the first element is the top of the stack. The third line contains n numbers a1, a2, . . . ,
an( Each ai is 1 and 0). The first number represents the first person of the queue who like sada
dosa if a1 = 0 or masala dosa if a1 = 1.
Output: The number of employees who will not be able to
have the breakfast. 
 Input : 3
0 1 1
1 0 1
Output : 0
Explanation: The following happensin each iteration:
1. The employee at the front goes to the back. The stack is now [0 1 1] and queue is [0 1 1].
2. The employee at the front takes the sada dosa. The stack is now [1 1] and queue is [1 1].
3. The employee at the front takes the masala dosa. The stack is now [1] and queue is [1].
4. The employee at the front takes the masala dosa. The stack is now [] and queue is [].*/
/* Author: Gopisai
 * Date: 25/9/2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>

/* Define a structure for each node in the stack and queue */
typedef struct Cafeteria {
    int iData;
    struct Cafeteria *next;
} Dosa,Employee;
/* Global variables */
Dosa *sfront = NULL, *srear = NULL;
Employee *qfront = NULL, *qrear = NULL;
/** FUNCTION PROTOTYPES */
void createStack(int );
void createQueue(int );
void printStack();
void printQueue();
void Pop(void) ;
void Dequeue(void); 
void Enqueue();
/* MAIN PROGRAM */
/* main : creating stack and queue */
int main()
{
    int iNum, iIndex1, iIndex2,flag=0;
    printf("Enter the number  ");
    scanf("%d", &iNum);

    /* Creating the stack and queue*/
    createStack(iNum);
    createQueue(iNum);
    printStack();
    printQueue();
    /* Checking Dosas and Employees */
      for (iIndex1 = 0; iIndex1 < iNum; iIndex1++) {

        for (iIndex2 = 0; iIndex2 < iNum * iNum; iIndex2++) {

            if (sfront->iData == qfront->iData) {

                flag=1;

                Pop();

                Dequeue();

                printStack();
                printQueue();
		iNum--;
		iIndex1--;
                break;

            }

            else{

                Enqueue();

            }

        }

        if(flag!=1)

                break;

        else

                flag=0;

    }

    printf("Remaining people %d\n", iNum);
}

/* createStack: To create stack of n Dosas */
/* Author: Gopisai
 * Date: 25/9/2024
 */
void createStack(int iNum)
{
    Dosa *new = NULL;
    int iVar, val;
    printf("Enter the elements for the stack:\n");
    for (iVar = 0; iVar < iNum; iVar++) {
        new = (Dosa *)malloc(sizeof(Dosa));
        new->next = NULL;
        scanf("%d", &val);
        new->iData = val;
        if (sfront == NULL) {
            sfront = new;
        } else {
            srear->next = new;
        }
        srear = new;
    }
}
/* createQueue: To create queue of n employees */
/* Author: Gopisai
 * Date: 25/9/2024
 */
void createQueue(int iNum)
{
    Employee *new = NULL;
    int i, val;
    printf("Enter the elements for the queue:\n");
    for (i = 0; i < iNum; i++) {
        new = (Employee *)malloc(sizeof(Employee));
        new->next = NULL;
        scanf("%d", &val);
        new->iData = val;
        if (qfront == NULL) {
            qfront = new;
        }
        else {
            qrear->next = new;
        }
        qrear = new;
    }

}
/* printStack: To print stack dosas */
/* Author: Gopisai
 * Date: 25/9/2024
 */
void printStack()
{
    Dosa *head = sfront;
    printf("Dosa Stack is ");
    while (head != NULL) {
        printf("%d ", head->iData);
        head = head->next;
    }
    printf("\n");

}
/* printQueue: To print queue employees */
/* Author: Gopisai
 * Date: 25/9/2024
 */
void printQueue() {
    Employee *head = qfront;
    printf("Employee Queue ");
    while (head != NULL) {
        printf("%d ", head->iData);
        head = head->next;
    }
    printf("\n\n");
}
/* Pop: To remove an elemnt from stack */
/* Author: Gopisai
 * Date: 25/9/2024
 */
void Pop(void) {

    Dosa *tmp = NULL;

    tmp = sfront;

    sfront = sfront->next;

    free(tmp);

    return;

}
 

/* DeQueue(): To dequeue an element from the queue */

/* Author: Gopisai
 * Date: 25/9/2024
 */

void Dequeue(void) {

    Employee *tmp = NULL;

    tmp = qfront;

    qfront = qfront->next;

    free(tmp);

    return;

}

/* Enqueue: To add node */
/* Author: Gopisai
 * Date: 25/9/2024
 */
void Enqueue(void) {
    Employee *tmp = NULL;
    /* adding node at end */
    tmp = qfront;
    qfront = qfront->next;
    tmp->next = NULL;
    qrear->next = tmp;
    qrear = tmp;
    return;
}
/* End Enqueue */
