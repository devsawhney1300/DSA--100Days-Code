#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
struct Node** createQueue(int n) {
    return (struct Node*)malloc(n * sizeof(struct Node));
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** queue = createQueue(n);
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (front < rear && i < n) {
        struct Node* curr = queue[front++];
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    free(queue);
    return root;
}
void levelOrder(struct Node* root) {
    if (!root) return;
    struct Node** queue = createQueue(1000);
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* curr = queue[front++];
        printf("%d ", curr->val);
        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
    free(queue);
}
int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    levelOrder(root);
    free(arr);
    return 0;
}