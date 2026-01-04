#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

void inorder(struct node *root) {
    if(root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root = malloc(sizeof(struct node));
    root->data = 10;
    root->left = root->right = NULL;

    inorder(root);
    return 0;
}

