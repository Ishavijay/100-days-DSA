//Construct a Binary Tree from the given level-order traversal.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// create node
struct node* newNode(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// build tree from level order array
struct node* build(int arr[], int n, int i)
{
    if (i >= n || arr[i] == -1)
        return NULL;

    struct node* root = newNode(arr[i]);

    root->left = build(arr, n, 2*i + 1);
    root->right = build(arr, n, 2*i + 2);

    return root;
}

// inorder traversal
void inorder(struct node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = build(arr, n, 0);

    inorder(root);

    return 0;
}