#include <stdio.h>
#include <stdlib.h>

/* Tree structure */
typedef struct tree {
    struct tree *left;
    int iData;
    struct tree *right;
} TREE;

/* FUNCTION PROTOTYPES */
void addChild(TREE **, int, int, int);
int countNodes(TREE *, int *);

/* MAIN PROGRAM */
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    TREE *nodes[n+1];  // Array of pointers to hold all nodes (1-indexed)
    for (int i = 1; i <= n; i++) {
        nodes[i] = (TREE *)malloc(sizeof(TREE));
        nodes[i]->iData = i;
        nodes[i]->left = nodes[i]->right = NULL;
    }

    // Reading the left and right children for each node
    for (int i = 1; i <= n; i++) {
        int left, right;
        scanf("%d %d", &left, &right);
        addChild(nodes, i, left, right);  // Adding children to node i
    }

    int subtreeSize[n+1];  // Array to store subtree sizes
    countNodes(nodes[1], subtreeSize);  // Calculate subtree sizes starting from root (node 1)

    // Output the number of nodes in the subtree rooted at each node
    for (int i = 1; i <= n; i++) {
        printf("%d ", subtreeSize[i]);
    }
    printf("\n");

    return 0;
}

/* Function to add left and right children to a node */
void addChild(TREE **nodes, int parent, int left, int right) {
    if (left != 0) {
        nodes[parent]->left = nodes[left];  // Assign the left child
    }
    if (right != 0) {
        nodes[parent]->right = nodes[right];  // Assign the right child
    }
}

/* Function to count the number of nodes in the subtree */
int countNodes(TREE *pPtr, int *subtree) {
    if (pPtr == NULL) {
        return 0;
    }

    int ileft = countNodes(pPtr->left, subtree);
    int iright = countNodes(pPtr->right, subtree);
    int total = 1 + ileft + iright;  // Including the current node

    subtree[pPtr->iData] = total;
    return total;
}

