/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure for stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Push function
void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop function
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Function to evaluate postfix expression
int evaluatePostfix(char* expr) {
    Node* stack = NULL;
    char* token = strtok(expr, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // Operand
            int num = atoi(token);
            push(&stack, num);
        } else {
            // Operator
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            switch (token[0]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
                default:
                    printf("Invalid operator: %s\n", token);
                    exit(1);
            }
        }
        token = strtok(NULL, " ");
    }

    int result = pop(&stack);
    if (stack != NULL) {
        printf("Warning: Stack not empty after evaluation\n");
    }
    return result;
}

int main() {
    char expr[100];

    printf("Enter postfix expression (space-separated): ");
    fgets(expr, sizeof(expr), stdin);

    // Remove newline character from fgets
    expr[strcspn(expr, "\n")] = 0;

    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);

    return 0;
}
