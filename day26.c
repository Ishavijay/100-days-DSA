/*Problem: Doubly Linked List Insertion and Traversal - Implement 
using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    int n, value;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = tail;

        if(head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
    }

    // Forward traversal
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}