#include <stdio.h>
#include <stdlib.h>

#define MAXN 101

struct Node {
    int data;
    struct Node* next;
};

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

// DFS function to detect cycle
int dfs(int v, struct Node* graph[], int visited[], int recStack[]) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = graph[v];
    while (temp) {
        int neighbor = temp->data;

        // If not visited → DFS
        if (!visited[neighbor]) {
            if (dfs(neighbor, graph, visited, recStack))
                return 1;
        }
        // If already in recursion stack → cycle
        else if (recStack[neighbor]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[v] = 0; // backtrack
    return 0;
}

// Main function to check cycle
int hasCycle(int n, struct Node* graph[]) {
    int visited[MAXN] = {0};
    int recStack[MAXN] = {0};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, visited, recStack))
                return 1;
        }
    }
    return 0;
}

// Driver code (for local testing)
int main() {
    int n = 4;
    struct Node* graph[MAXN] = {NULL};

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1); // cycle here

    if (hasCycle(n, graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}