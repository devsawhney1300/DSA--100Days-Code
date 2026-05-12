#include <stdio.h>
#include <stdlib.h>

// Node for linked list (bucket)
typedef struct Node {
    float data;
    struct Node* next;
} Node;

// Insert node in sorted order (for each bucket)
Node* sortedInsert(Node* head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at beginning or empty bucket
    if (head == NULL || value < head->data) {
        newNode->next = head;
        return newNode;
    }

    // Traverse and insert
    Node* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Bucket Sort function
void bucketSort(float arr[], int n) {
    // Step 1: Create n buckets
    Node** buckets = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];   // bucket index
        buckets[index] = sortedInsert(buckets[index], arr[i]);
    }

    // Step 3: Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[k++] = current->data;
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(buckets);
}

// Print array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

// Main
int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}