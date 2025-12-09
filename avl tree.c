#include <stdio.h>
#include <stdlib.h>

// AVL Tree Node Structure
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int height;
};

// Function to get height of a node
int height(struct TreeNode* node) {
    return (node == NULL) ? 0 : node->height;
}

// Utility to get max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node
struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Right Rotate
struct TreeNode* rightRotate(struct TreeNode* y) {
    struct TreeNode* x = y->left;
    struct TreeNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Left Rotate
struct TreeNode* leftRotate(struct TreeNode* x) {
    struct TreeNode* y = x->right;
    struct TreeNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

// Get Balance Factor
int getBalance(struct TreeNode* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

// AVL Insertion
struct TreeNode* insert(struct TreeNode* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node; // Duplicates not allowed

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Balance the tree
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// In-order Traversal
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Build AVL from sorted array
struct TreeNode* sortedArrayToAVL(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct TreeNode* node = createNode(arr[mid]);

    node->left = sortedArrayToAVL(arr, start, mid - 1);
    node->right = sortedArrayToAVL(arr, mid + 1, end);

    node->height = 1 + max(height(node->left), height(node->right));
    return node;
}

// Free AVL Tree memory
void freeAVLTree(struct TreeNode* root) {
    if (root) {
        freeAVLTree(root->left);
        freeAVLTree(root->right);
        free(root);
    }
}

// Main function
int main() {
    // Sorted input (hardcoded instead of file)
    int sortedInput[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(sortedInput) / sizeof(sortedInput[0]);

    struct TreeNode* root = NULL;
    root = sortedArrayToAVL(sortedInput, 0, size - 1);

    printf("AVL Tree constructed from sorted array.\n");

    int choice, key;

    do {
        printf("\nAVL Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. In-order Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("In-order Traversal: ");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 3);

    freeAVLTree(root);
    return 0;
}
