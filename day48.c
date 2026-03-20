#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int val) {
    if (val == -1) return NULL;

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int countLeaves(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (n == 0 || arr[0] == -1) {
        printf("0");
        return 0;
    }

    Node* nodes[n];

    for (int i = 0; i < n; i++)
        nodes[i] = newNode(arr[i]);

    int j = 1;

    for (int i = 0; i < n && j < n; i++) {
        if (nodes[i] != NULL) {
            nodes[i]->left = nodes[j++];
            if (j < n)
                nodes[i]->right = nodes[j++];
        }
    }

    printf("%d", countLeaves(nodes[0]));

    return 0;
}