//A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);

    int capacity = 100;
    int *dq = (int *)malloc(capacity * sizeof(int));

    int front = -1;
    int rear = -1;
    int size = 0;

    for (int i = 0; i < N; i++)
    {
        char op[20];
        scanf(" %s", op);

        // push_back
        if (strcmp(op, "push_back") == 0)
        {
            int x;
            scanf("%d", &x);

            if (size == 0)
            {
                front = rear = 0;
            }
            else
            {
                rear++;
            }

            dq[rear] = x;
            size++;
        }

        // push_front
        else if (strcmp(op, "push_front") == 0)
        {
            int x;
            scanf("%d", &x);

            if (size == 0)
            {
                front = rear = 0;
                dq[front] = x;
            }
            else
            {
                for (int j = rear; j >= front; j--)
                    dq[j + 1] = dq[j];

                dq[front] = x;
                rear++;
            }

            size++;
        }

        // pop_front
        else if (strcmp(op, "pop_front") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", dq[front]);

                for (int j = front; j < rear; j++)
                    dq[j] = dq[j + 1];

                rear--;
                size--;

                if (size == 0)
                    front = rear = -1;
            }
        }

        // pop_back
        else if (strcmp(op, "pop_back") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", dq[rear]);

                rear--;
                size--;

                if (size == 0)
                    front = rear = -1;
            }
        }

        // front
        else if (strcmp(op, "front") == 0)
        {
            if (size == 0)
                printf("-1\n");
            else
                printf("%d\n", dq[front]);
        }

        // back
        else if (strcmp(op, "back") == 0)
        {
            if (size == 0)
                printf("-1\n");
            else
                printf("%d\n", dq[rear]);
        }

        // size
        else if (strcmp(op, "size") == 0)
        {
            printf("%d\n", size);
        }

        // empty
        else if (strcmp(op, "empty") == 0)
        {
            if (size == 0)
                printf("1\n");
            else
                printf("0\n");
        }

        // clear
        else if (strcmp(op, "clear") == 0)
        {
            front = rear = -1;
            size = 0;
        }
    }

    free(dq);
    return 0;
}