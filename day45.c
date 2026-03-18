//Find the height (maximum depth) of a given binary tree.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// function to find height
int height(struct Node* root)
{
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + (left > right ? left : right);
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n == 0)
    {
        printf("0");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (arr[0] == -1)
    {
        printf("0");
        return 0;
    }

    // create root
    struct Node* root = createNode(arr[0]);

    // queue for level order build
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n)
    {
        struct Node* curr = queue[front++];

        // left child
        if (i < n && arr[i] != -1)
        {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // right child
        if (i < n && arr[i] != -1)
        {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    printf("%d", height(root));

    return 0;
}