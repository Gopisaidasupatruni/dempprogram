#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int row, column;
    double value;
    struct node* rowPtr;  
    struct node* colPtr;
} node;

typedef struct matrix {
    node** rowList;     
    node** columnList; 
    int rows, columns;
} matrix;

matrix* createMatrix(int rows, int columns);
void insertValue(matrix* m, int row, int column, double value);
void displayMatrix(matrix* m);

int main() {
    int rows, columns;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &columns);

    /* Create the matrix with the given dimensions */
    matrix* mat = createMatrix(rows, columns);

    /* Insert sample values into the matrix */
    insertValue(mat, 0, 0, 1.1);
    insertValue(mat, 1, 1, 2.5);

    /* Display the matrix */
    printf("\nMatrix elements:\n");
    displayMatrix(mat);

    return 0;
}

/* createMatrix: To initialize the matrix structure */
matrix* createMatrix(int rows, int columns) {
    matrix* m = (matrix*)malloc(sizeof(matrix));
    m->rows = rows;
    m->columns = columns;

    /* Allocate memory for rowList and columnList arrays */
    m->rowList = (node**)calloc(rows, sizeof(node*));
    m->columnList = (node**)calloc(columns, sizeof(node*));

    return m;
}

/* insertValue: Insert a value at a specific row and column */
void insertValue(matrix* m, int row, int column, double value) {
    if (row >= m->rows || column >= m->columns) {
        printf("Invalid row or column index\n");
        return;
    }

    /* Create a new node for the value */
    node* newNode = (node*)malloc(sizeof(node));
    newNode->row = row;
    newNode->column = column;
    newNode->value = value;
    newNode->rowPtr = NULL;
    newNode->colPtr = NULL;

    /* Insert into the row list */
    node* current = m->rowList[row];
    node* prev = NULL;

    /* Traverse to the correct position in the row */
    while (current != NULL && current->column < column) {
        prev = current;
        current = current->rowPtr;
    }

    if (prev == NULL) {
        newNode->rowPtr = m->rowList[row];
        m->rowList[row] = newNode;
    } else {
        newNode->rowPtr = prev->rowPtr;
        prev->rowPtr = newNode;
    }

    current = m->columnList[column];
    prev = NULL;

    while (current != NULL && current->row < row) {
        prev = current;
        current = current->colPtr;
    }

    if (prev == NULL) {
        newNode->colPtr = m->columnList[column];
        m->columnList[column] = newNode;
    } else {
        newNode->colPtr = prev->colPtr;
        prev->colPtr = newNode;
    }
}

/* displayMatrix: To display all elements of the matrix */
void displayMatrix(matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        node* temp = m->rowList[i];
        for (int j = 0; j < m->columns; j++) {
            if (temp != NULL && temp->column == j) {
                printf("%.1f ", temp->value);
                temp = temp->rowPtr;
            } else {
                printf("0.0 ");
            }
        }
        printf("\n");
    }
}

