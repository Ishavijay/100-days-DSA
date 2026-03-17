//Given a queue of integers, reverse the queue using a stack.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);

    // dynamic queue
    int *queue = (int *)malloc(N * sizeof(int));

    // dynamic stack
    int *stack = (int *)malloc(N * sizeof(int));

    int front = 0, rear = -1;
    int top = -1;

    // input queue
    for (int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);

        rear++;
        queue[rear] = x;
    }

    // move queue → stack
    while (front <= rear)
    {
        top++;
        stack[top] = queue[front];
        front++;
    }

    // reset queue
    front = 0;
    rear = -1;

    // move stack → queue
    while (top >= 0)
    {
        rear++;
        queue[rear] = stack[top];
        top--;
    }

    // print reversed queue
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    free(queue);
    free(stack);

    return 0;
}