/* Author : Gopisai
 * Date: 5/11/2024
 */
/* REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>

/* Self-referential structure for matrix node */
typedef struct matrix_node {
    int row, column;
    double value;
    struct matrix_node* nextRow;
    struct matrix_node* nextColumn;
} matrix_node;

/* Structure representing sparse matrix */
typedef struct sparse_matrix {
    matrix_node** rowHeaders;
    matrix_node** colHeaders;
    int rowCount, colCount;
} sparse_matrix;

/* AllocateNode: Allocates and initializes a new node */
matrix_node* AllocateNode(int row, int col) {
    matrix_node* newNode = (matrix_node*)malloc(sizeof(matrix_node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->row = row;
    newNode->column = col;
    scanf("%lf", &newNode->value);
    newNode->nextRow = NULL;
    newNode->nextColumn = NULL;
    return newNode;
}

/* DisplayMatrix: Prints the matrix */
void DisplayMatrix(sparse_matrix* mat) {
    for (int i = 0; i < mat->rowCount; i++) {
        matrix_node* currentNode = mat->rowHeaders[i];
        for (int j = 0; j < mat->colCount; j++) {
            if (currentNode == NULL || currentNode->column != j) {
                printf("0.00 ");
            } else {
                printf("%.2lf ", currentNode->value);
                currentNode = currentNode->nextRow;
            }
        }
        printf("\n");
    }
}

/* CheckDuplicateValue: Checks if a specific value exists in the matrix */
int CheckDuplicateValue(sparse_matrix* mat, double value) {
    for (int i = 0; i < mat->rowCount; i++) {
        matrix_node* currentNode = mat->rowHeaders[i];
        while (currentNode != NULL) {
            if (currentNode->value == value)
                return 1;
            currentNode = currentNode->nextRow;
        }
    }
    return 0;
}

/* InitializeMatrix: Allocates and initializes a sparse matrix */
sparse_matrix* InitializeMatrix(sparse_matrix* mat) {
    mat->rowHeaders = (matrix_node**)malloc(sizeof(matrix_node*) * mat->rowCount);
    mat->colHeaders = (matrix_node**)malloc(sizeof(matrix_node*) * mat->colCount);

    for (int i = 0; i < mat->rowCount; i++) {
        mat->rowHeaders[i] = NULL;
    }
    for (int j = 0; j < mat->colCount; j++) {
        mat->colHeaders[j] = NULL;
    }

    for (int i = 0; i < mat->rowCount; i++) {
        for (int j = 0; j < mat->colCount; j++) {
            printf("Enter (%d,%d) value: ", i, j);
            matrix_node* newNode = AllocateNode(i, j);
            
            if (mat->rowHeaders[i] == NULL) {
                mat->rowHeaders[i] = newNode;
            } else {
                matrix_node* rowTraverse = mat->rowHeaders[i];
                while (rowTraverse->nextRow != NULL) {
                    rowTraverse = rowTraverse->nextRow;
                }
                rowTraverse->nextRow = newNode;
            }

            if (mat->colHeaders[j] == NULL) {
                mat->colHeaders[j] = newNode;
            } else {
                matrix_node* colTraverse = mat->colHeaders[j];
                while (colTraverse->nextColumn != NULL) {
                    colTraverse = colTraverse->nextColumn;
                }
                colTraverse->nextColumn = newNode;
            }
        }
    }
    return mat;
}

/* ExpandMatrix: Doubles the size of the matrix */
int ExpandMatrix(sparse_matrix** matRef) {
    sparse_matrix* tempMat = (sparse_matrix*)realloc(*matRef, sizeof(sparse_matrix));
    if (tempMat == NULL) return 0;

    tempMat->rowHeaders = (matrix_node**)realloc(tempMat->rowHeaders, sizeof(matrix_node*) * tempMat->rowCount * 2);
    tempMat->colHeaders = (matrix_node**)realloc(tempMat->colHeaders, sizeof(matrix_node*) * tempMat->colCount * 2);
    if (tempMat->rowHeaders == NULL || tempMat->colHeaders == NULL) return 0;

    for (int i = tempMat->rowCount; i < tempMat->rowCount * 2; i++) {
        tempMat->rowHeaders[i] = NULL;
    }
    for (int j = tempMat->colCount; j < tempMat->colCount * 2; j++) {
        tempMat->colHeaders[j] = NULL;
    }

    *matRef = tempMat;
    (*matRef)->rowCount *= 2;
    (*matRef)->colCount *= 2;
    return 1;
}

/* TransposeMatrix: Transposes the matrix in-place */
int TransposeMatrix(sparse_matrix **matRef) {
    int i, j;
    sparse_matrix* mat = *matRef;

    int newRowCount = mat->colCount;
    int newColCount = mat->rowCount;

    matrix_node** newRowHeaders = (matrix_node**)malloc(sizeof(matrix_node*) * newRowCount);
    matrix_node** newColHeaders = (matrix_node**)malloc(sizeof(matrix_node*) * newColCount);

    if (newRowHeaders == NULL || newColHeaders == NULL) {
        return 0;
    }

    for (i = 0; i < newRowCount; i++) {
        newRowHeaders[i] = NULL;
    }
    for (j = 0; j < newColCount; j++) {
        newColHeaders[j] = NULL;
    }

    for (i = 0; i < mat->rowCount; i++) {
        matrix_node* current = mat->rowHeaders[i];
        while (current != NULL) {
            int newRow = current->column;
            int newCol = current->row;
            
            matrix_node* newNode = (matrix_node*)malloc(sizeof(matrix_node));
            newNode->row = newRow;
            newNode->column = newCol;
            newNode->value = current->value;
            newNode->nextRow = NULL;
            newNode->nextColumn = NULL;

            if (newRowHeaders[newRow] == NULL) {
                newRowHeaders[newRow] = newNode;
            } else {
                matrix_node* tempNode = newRowHeaders[newRow];
                while (tempNode->nextRow != NULL) {
                    tempNode = tempNode->nextRow;
                }
                tempNode->nextRow = newNode;
            }

            if (newColHeaders[newCol] == NULL) {
                newColHeaders[newCol] = newNode;
            } else {
                matrix_node* tempNode = newColHeaders[newCol];
                while (tempNode->nextColumn != NULL) {
                    tempNode = tempNode->nextColumn;
                }
                tempNode->nextColumn = newNode;
            }

            current = current->nextRow;
        }
    }

    free(mat->rowHeaders);
    free(mat->colHeaders);

    mat->rowCount = newRowCount;
    mat->colCount = newColCount;
    mat->rowHeaders = newRowHeaders;
    mat->colHeaders = newColHeaders;

    return 1;
}

int main() {
    int rows, cols, choice, result;
    double searchValue;

    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &rows, &cols);

    sparse_matrix* matrix = (sparse_matrix*)malloc(sizeof(sparse_matrix));
    matrix->rowCount = rows;
    matrix->colCount = cols;
    matrix->rowHeaders = (matrix_node**)malloc(sizeof(matrix_node*) * rows);
    matrix->colHeaders = (matrix_node**)malloc(sizeof(matrix_node*) * cols);

    for (int i = 0; i < rows; i++) {
        matrix->rowHeaders[i] = NULL;
    }
    for (int j = 0; j < cols; j++) {
        matrix->colHeaders[j] = NULL;
    }

    while (1) {
        printf("Options:\n1. InitializeMatrix\n2. DisplayMatrix\n3. CheckDuplicateValue\n4. TransposeMatrix\n5. ExpandMatrix\n6. Exit\nSelect an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                InitializeMatrix(matrix);
                break;
            case 2:
                DisplayMatrix(matrix);
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%lf", &searchValue);
                result = CheckDuplicateValue(matrix, searchValue);
                printf(result ? "Value found\n" : "Value not found\n");
                break;
            case 4:
                TransposeMatrix(&matrix);
                DisplayMatrix(matrix);
                break;
            case 5:
                result = ExpandMatrix(&matrix);
                printf(result ? "Matrix expanded\n" : "Expansion failed\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

}   

