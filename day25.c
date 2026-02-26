/*Problem: Count Occurrences of an Element in Linked List - 
Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value, key;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    // Creating linked list
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Read key
    scanf("%d", &key);

    // Count occurrences
    int count = 0;
    struct Node* temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}