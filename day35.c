//Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue operation
void enqueue(int value)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = value;
    newnode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

// Display queue
void display()
{
    struct Node *temp = front;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(value);
    }

    display();

    return 0;
}