#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Pair {
    struct Node* node;
    int hd;
};

struct Queue {
    struct Pair data[2000];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->data[q->rear].node = node;
    q->data[q->rear].hd = hd;
    q->rear++;
}

struct Pair dequeue(struct Queue* q) {
    return q->data[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Queue q = {0};

    enqueue(&q, root, 0);
    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct Pair p = dequeue(&q);
        struct Node* curr = p.node;

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(&q, curr->left, 0);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(&q, curr->right, 0);
        }
        i++;
    }
    return root;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    int map[4000][200];
    int size[4000] = {0};

    struct Queue q = {0};
    int offset = 2000;

    enqueue(&q, root, 0);

    while (!isEmpty(&q)) {
        struct Pair p = dequeue(&q);
        struct Node* node = p.node;
        int hd = p.hd + offset;

        map[hd][size[hd]++] = node->data;

        if (node->left)
            enqueue(&q, node->left, p.hd - 1);
        if (node->right)
            enqueue(&q, node->right, p.hd + 1);
    }

    for (int i = 0; i < 4000; i++) {
        if (size[i] > 0) {
            for (int j = 0; j < size[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}