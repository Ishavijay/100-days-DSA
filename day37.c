//Implement a Priority Queue using an array. An element with smaller value has higher priority
// Implement a Priority Queue using array (smaller value = higher priority)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);

    int *pq = (int *)malloc(N * sizeof(int));
    int size = 0;

    for (int i = 0; i < N; i++)
    {
        char op[20];
        scanf(" %s", op);   // space before %s fixes input issue

        // INSERT
        if (strcmp(op, "insert") == 0)
        {
            int x;
            scanf("%d", &x);

            int j = size - 1;

            while (j >= 0 && pq[j] > x)
            {
                pq[j + 1] = pq[j];
                j--;
            }

            pq[j + 1] = x;
            size++;
        }

        // DELETE
        else if (strcmp(op, "delete") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", pq[0]);

                for (int j = 0; j < size - 1; j++)
                {
                    pq[j] = pq[j + 1];
                }

                size--;
            }
        }

        // PEEK
        else if (strcmp(op, "peek") == 0)
        {
            if (size == 0)
                printf("-1\n");
            else
                printf("%d\n", pq[0]);
        }
    }

    free(pq);
    return 0;
}