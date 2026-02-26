#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at the end
void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);

    // If list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    
    // Traverse to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Traverse forward
void printForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Free memory
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    printForward(head);
    freeList(head);

    return 0;
}