//Implement the solution for this problem.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// BST insert (for building tree)
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// BST search
struct Node* searchBST(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchBST(root->left, key);

    return searchBST(root->right, key);
}

int main() {
    struct Node* root = NULL;

    // Example tree
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);

    int key;
    scanf("%d", &key);

    struct Node* result = searchBST(root, key);

    if (result != NULL)
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}