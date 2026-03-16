//Implement a Min Heap using an array where the smallest element is always at the root.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// heapify up
void heapifyUp(int heap[], int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (heap[parent] > heap[index])
        {
            swap(&heap[parent], &heap[index]);
            index = parent;
        }
        else
            break;
    }
}

// heapify down
void heapifyDown(int heap[], int size, int index)
{
    while (1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index)
        {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        }
        else
            break;
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int *heap = (int *)malloc(N * sizeof(int));
    int size = 0;

    for (int i = 0; i < N; i++)
    {
        char op[10];
        scanf(" %s", op);

        // insert
        if (strcmp(op, "insert") == 0)
        {
            int x;
            scanf("%d", &x);

            heap[size] = x;
            heapifyUp(heap, size);
            size++;
        }

        // deleteMin
        else if (strcmp(op, "delete") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", heap[0]);

                heap[0] = heap[size - 1];
                size--;

                heapifyDown(heap, size, 0);
            }
        }

        // peek
        else if (strcmp(op, "peek") == 0)
        {
            if (size == 0)
                printf("-1\n");
            else
                printf("%d\n", heap[0]);
        }
    }

    free(heap);
    return 0;
}