//Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d", &n);

    int *queue = (int *)malloc(n * sizeof(int));

    int front = 0, rear = -1;
    int size = n;

    // enqueue n elements
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        rear = (rear + 1) % size;
        queue[rear] = x;
    }

    scanf("%d", &m);

    // circular dequeue (rotation)
    for (int i = 0; i < m; i++)
    {
        int temp = queue[front];   // take front

        front = (front + 1) % size; // remove front

        rear = (rear + 1) % size;   // move rear
        queue[rear] = temp;         // add at rear
    }

    // print queue
    int i = front;
    for (int count = 0; count < size; count++)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % size;
    }

    free(queue);
    return 0;
}