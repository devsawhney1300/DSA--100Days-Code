#include <stdio.h>
#include <stdlib.h>

#define MAXN 101

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// Stack
int stack[MAXN];
int top = -1;

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Add edge (directed)
void addEdge(struct Node* graph[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph[u];
    graph[u] = newNode;
}

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int v, struct Node* graph[], int visited[]) {
    visited[v] = 1;

    struct Node* temp = graph[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(temp->data, graph, visited);
        }
        temp = temp->next;
    }

    push(v);  // push after visiting children
}

// Topological sort
void topoSort(int n, struct Node* graph[]) {
    int visited[MAXN] = {0};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited);
        }
    }

    // Print stack (reverse order)
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Driver
int main() {
    int n = 6;
    struct Node* graph[MAXN] = {NULL};

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    printf("Topological Order: ");
    topoSort(n, graph);

    return 0;
}