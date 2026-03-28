#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < n) nodes[i]->left = nodes[left];
            if (right < n) nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

// Queue implementation
struct QNode {
    struct Node* node;
    struct QNode* next;
};

void enqueue(struct QNode** front, struct QNode** rear, struct Node* node) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->node = node;
    temp->next = NULL;

    if (*rear == NULL) {
        *front = *rear = temp;
        return;
    }

    (*rear)->next = temp;
    *rear = temp;
}

struct Node* dequeue(struct QNode** front, struct QNode** rear) {
    if (*front == NULL) return NULL;

    struct QNode* temp = *front;
    struct Node* node = temp->node;

    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;

    free(temp);
    return node;
}

// Zigzag Traversal
void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;

    struct QNode* front = NULL;
    struct QNode* rear = NULL;

    enqueue(&front, &rear, root);

    int leftToRight = 1;

    while (front != NULL) {
        int size = 0;
        struct QNode* temp = front;

        // count nodes in current level
        while (temp) {
            size++;
            temp = temp->next;
        }

        int arr[size];
        int index = leftToRight ? 0 : size - 1;

        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue(&front, &rear);

            arr[index] = curr->data;

            if (leftToRight)
                index++;
            else
                index--;

            if (curr->left)
                enqueue(&front, &rear, curr->left);
            if (curr->right)
                enqueue(&front, &rear, curr->right);
        }

        // print current level
        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}