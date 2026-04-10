#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Graph
struct Node* adj[MAX];

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (directed)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// BFS function
void BFS(int n, int s) {
    int visited[MAX] = {0};
    int queue[MAX];

    int front = 0, rear = 0;

    // start from source
    visited[s] = 1;
    queue[rear++] = s;

    printf("BFS Traversal: ");

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        struct Node* temp = adj[u];

        while (temp != NULL) {
            int v = temp->data;

            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }

            temp = temp->next;
        }
    }
}

// Driver code
int main() {
    int n = 5;

    // initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    // edges
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    int source = 0;

    BFS(n, source);

    return 0;
}