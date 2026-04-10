#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// adjacency list node
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];

// create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// add edge (undirected)
void addEdge(int u, int v) {
    struct Node* n1 = createNode(v);
    n1->next = adj[u];
    adj[u] = n1;

    struct Node* n2 = createNode(u);
    n2->next = adj[v];
    adj[v] = n2;
}

// DFS to detect cycle
int dfs(int node, int parent, int visited[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];

    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited))
                return 1;
        }
        else if (neighbor != parent) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    return 0;
}

// check cycle in graph
int hasCycle(int n) {
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited))
                return 1;
        }
    }

    return 0;
}

// driver
int main() {
    int n = 5;

    // initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    // edges (try changing these)
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 1); // creates cycle

    if (hasCycle(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}