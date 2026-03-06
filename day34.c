// Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// PUSH operation
void push(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

// POP operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    int i = 0;

    while (exp[i] != '\0') {

        if (isdigit(exp[i])) {
            push(exp[i] - '0');   // convert char to int
        }

        else if (exp[i] == '+' || exp[i] == '-' ||
                 exp[i] == '*' || exp[i] == '/') {

            int op2 = pop();
            int op1 = pop();
            int result;

            switch (exp[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
        }

        i++;
    }

    return pop();
}

int main() {

    char exp[] = "231*+9-";

    int result = evaluatePostfix(exp);

    printf("Result = %d", result);

    return 0;
}