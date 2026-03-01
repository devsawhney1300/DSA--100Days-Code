#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) return 0;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Create linked list
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    int k;
    scanf("%d", &k);

    // Edge case
    if (k == 0 || head == NULL)
    {
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // Step 1: Find length and last node
    int length = 1;
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    // Step 2: Optimize k
    k = k % length;
    if (k == 0) {
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // Step 3: Make circular
    tail->next = head;

    // Step 4: Traverse to (length - k)th node
    int steps = length - k;
    struct Node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Step 5: Set new head and break circle
    head = newTail->next;
    newTail->next = NULL;

    // Print rotated list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}