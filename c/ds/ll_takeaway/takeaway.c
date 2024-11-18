/* In the structure above, we are using two arrays of linked nodes to create a structure that can be traversed starting from any row index or column index. When a new node needs to be inserted, we must traverse the list from corresponding row index and corresponding column index and then link the node into the structure. You can use same logic in both cases, except that row indices are traversed and linked using the row_ptr and columns are traversed and linked using the column_ptr.

 

Task to perform : Write Unit Test Case, Apply coding standards and implement following task.

 

1.Suppose M is a matrix*, where matrix is as defined above. Write code to allocate enough space to initialize a matrix of n by m. 


2. Given a pointer to a node called ptr (assume all memory is allocated and node  initialized), write code to insert the node to the beginning of the each list.


3. Write a function int duplicatevalue(matrix* M, double value) that returns 1 if a  node with the value exists in the matrix. Return 0 if not.


4. Write a function int resize(matrix**) that doubles the rows and columns of the matrix. The old nodes need to be copied to the new matrix. Return 0 if success, 1 
if failure.


5. Write a function int transpose(matrix**) that takes the transpose of the matrix. Transpose of a matrix M is defined as a matrix M1 where rows of M are equivalent to columns of M1 and columns of M are equivalent to rows of M1. For example the transpose of M = {{1,2},{3,4}} is M1 = {{1,3},{2,4}}.
*/

/* Author : Gopisai
 * Date: 5/11/2024
 */
/* REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
 
/* self referential structure node */
typedef struct node {
    int row, column;
    double value;
    struct node* rowPtr;
    struct node* colPtr;
} node;
 /* structure representing matrix */
typedef struct matrix {
    node** rowList;
    node** columnList;
    int rows, columns;
} matrix;
/* CreateNode: To create a node */
node* CreateNode(int i, int j) {
    node* new = (node*)malloc(sizeof(node));
    new->row = i;
    new->column = j;
    scanf("%lf", &new->value);
    new->rowPtr = NULL;
    new->colPtr = NULL;
    return new;
}
/*PrintMatrix: To print matrix */
void PrintMatrix(matrix* M) {
    node* head = NULL;
    double x = 0;
    for (int i = 0; i < M->rows; i++) {
        head = M->rowList[i];
        for (int j = 0; j < M->columns; j++) {
            if (head == NULL || head->column != j) {
                printf("%.2lf ", x);
            } else {
                printf("%.2lf ", head->value);
                head = head->rowPtr;
            }
        }
        printf("\n");
    }
}
 
int duplicatevalue(matrix* M, double value) {
    node* head = NULL;
    for (int i = 0; i < M->rows; i++) {
        head = M->rowList[i];
        while (head != NULL) {
            if (head->value == value)
                return 1;
            head = head->rowPtr;
        }
    }
    return 0;
}
/* CreateMatrix: To create a matrix */
matrix* CreateMatrix(matrix* Mat) {
    node* new = NULL, * head = NULL;
    Mat->rowList = (node**)malloc(sizeof(node*) * Mat->rows);
    Mat->columnList = (node**)malloc(sizeof(node*) * Mat->columns);
    for (int i = 0; i < Mat->rows; i++) {
        Mat->rowList[i] = NULL;
    }
    for (int i = 0; i < Mat->columns; i++) {
        Mat->columnList[i] = NULL;
    }
 
    for (int i = 0; i < Mat->rows; i++) {
        for (int j = 0; j < Mat->columns; j++) {
            printf("Enter (%d,%d) value: ", i, j);
	    /* calling createnode to create a node with row and column index */
            new = CreateNode(i, j);
	    /* If the row list for row i is empty */
            if (Mat->rowList[i] == NULL) {
                Mat->rowList[i] = new;
            } else {
		    /*If the row list already has nodes*/
                head = Mat->rowList[i];
                while (head->rowPtr != NULL) {
                    head = head->rowPtr;
                }
                head->rowPtr = new;
            }
	    /*If the column list for row i is empty */
            if (Mat->columnList[j] == NULL) {
                Mat->columnList[j] = new;
            } else {
                head = Mat->columnList[j];
                while (head->colPtr != NULL) {
                    head = head->colPtr;
                }
                head->colPtr = new;
            }
        }
    }
    return Mat;
}
 
int resize(matrix** M) {
    matrix* Mat = (matrix*)realloc(*M, sizeof(matrix));
    if (Mat == NULL)
        return 0;
 
    Mat->rowList = (node**)realloc(Mat->rowList, sizeof(node*) * Mat->rows * 2);
    Mat->columnList = (node**)realloc(Mat->columnList, sizeof(node*) * Mat->columns * 2);
    if (Mat->rowList == NULL || Mat->columnList == NULL)
        return 0;
 
    for (int i = Mat->rows; i < Mat->rows * 2; i++) {
        Mat->rowList[i] = NULL;
    }
    for (int i = Mat->columns; i < Mat->columns * 2; i++) {
        Mat->columnList[i] = NULL;
    }
 
    *M = Mat;
    (*M)->rows *= 2;
    (*M)->columns *= 2;
    return 1;
}
/* transpose: To transpose a matrix*/
int transpose(matrix **Mat) {
    int i, j;
    node *current = NULL;

    int newRows = (*Mat)->columns;
    int newCols = (*Mat)->rows;

    node** newRowList = (node**)malloc(sizeof(node*) * newRows);
    node** newColList = (node**)malloc(sizeof(node*) * newCols);

    if (newRowList == NULL || newColList == NULL) {
        return 0;
    }

    for (i = 0; i < newRows; i++) {
        newRowList[i] = NULL;
    }
    for (i = 0; i < newCols; i++) {
        newColList[i] = NULL;
    }

    for (i = 0; i < (*Mat)->rows; i++) {
        current = (*Mat)->rowList[i];
        while (current != NULL) {
            int newRow = current->column;
            int newCol = current->row;
           /* Creating newnode in the transposed position */
            node* newNode = (node*)malloc(sizeof(node));
            if (newNode == NULL) {
                for (j = 0; j < newRows; j++) free(newRowList[j]);
                for (j = 0; j < newCols; j++) free(newColList[j]);
                free(newRowList);
                free(newColList);
                return 0;
            }

            newNode->row = newRow;
            newNode->column = newCol;
            newNode->value = current->value;
            newNode->rowPtr = NULL;
            newNode->colPtr = NULL;

	    /* Link the  new node in transposed matrix*/

            if (newRowList[newRow] == NULL) {
                newRowList[newRow] = newNode;
            } else {
                node* tempNode = newRowList[newRow];
                while (tempNode->rowPtr != NULL) {
                    tempNode = tempNode->rowPtr;
                }
                tempNode->rowPtr = newNode;
            }

            if (newColList[newCol] == NULL) {
                newColList[newCol] = newNode;
            } else {
                node* tempNode = newColList[newCol];
                while (tempNode->colPtr != NULL) {
                    tempNode = tempNode->colPtr;
                }
                tempNode->colPtr = newNode;
            }

            current = current->rowPtr;
        }
    }
    /* freeing original matrix memory */
    for (i = 0; i < (*Mat)->rows; i++) {
        current = (*Mat)->rowList[i];
        while (current != NULL) {
            node* next = current->rowPtr;
            free(current);
            current = next;
        }
    }
    free((*Mat)->rowList);
    free((*Mat)->columnList);
    /* updating matrix structure */
    (*Mat)->rows = newRows;
    (*Mat)->columns = newCols;
    (*Mat)->rowList = newRowList;
    (*Mat)->columnList = newColList;

    return 1;
}

int main() 
{
        int mrows, ncolumns, ichoice, iret;
        double value;
        printf("Enter rows and columns: ");
        scanf("%d%d", &mrows, &ncolumns);
        /* allocating memory for the matrix structure */
        matrix* M = (matrix*)malloc(sizeof(matrix));
        M->rows = mrows;
        M->columns = ncolumns;
        M->rowList = (node**)malloc(sizeof(node*) * mrows);
        M->columnList = (node**)malloc(sizeof(node*) * ncolumns);
        /* Initializing Row and Column Lists to NULL */
        for (int i = 0; i < mrows; i++) {
                M->rowList[i] = NULL;
        }
        for (int i = 0; i < ncolumns; i++) {
                M->columnList[i] = NULL;
        }
	/* switch case to select required operation */
 
        while (1) {
                printf("Options:\n1. CreateMatrix.\n2. PrintMatrix.\n3. DuplicateValue.\n4. Transpose.\n5. Resize.\n 6. exit. \nChoose your choice: ");
                scanf("%d", &ichoice);
                switch (ichoice) {
                        case 1:
                                M = CreateMatrix(M);
                                break;
                        case 2:
                                PrintMatrix(M);
                                break;
                        case 3:
                                printf("Enter value to check: ");
                                scanf("%lf", &value);
                                iret = duplicatevalue(M, value);
                                printf("%s\n", iret == 1 ? "found" : "Not found");
                                break;
                        case 4: matrix *M1=(matrix *)malloc(sizeof(matrix));
                                M1=M;
                                transpose(&M1);
                                PrintMatrix(M1);
                                break;
                        case 5:
                                iret = resize(&M);
                                printf("%s\n", iret == 1 ? "Resized successfully" : "Not resized");
                                break;
			case 6:
				return 1;
                        default:
                                printf("Invalid choice.\n");
                                break;
                }
        }
        return 0;

}
/* End main */
