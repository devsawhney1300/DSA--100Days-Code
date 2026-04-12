#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Min Heap Node
struct HeapNode {
    int vertex;
    int dist;
};

// Graph
struct Node* adj[MAX];

// Create new node
struct Node* createNode(int v, int w) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->vertex = v;
    new->weight = w;
    new->next = NULL;
    return new;
}

// Add edge
void addEdge(int u, int v, int w) {
    struct Node* new = createNode(v, w);
    new->next = adj[u];
    adj[u] = new;
}

// Min Heap
struct HeapNode heap[MAX];
int size = 0;

// Swap
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[i].dist < heap[(i - 1) / 2].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert into heap
void push(int v, int dist) {
    heap[size].vertex = v;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}

// Extract min
struct HeapNode pop() {
    struct HeapNode root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

int isEmpty() {
    return size == 0;
}

// Dijkstra
void dijkstra(int V, int src) {
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (!isEmpty()) {
        struct HeapNode node = pop();
        int u = node.vertex;

        struct Node* temp = adj[u];

        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int V = 5;

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    addEdge(0, 1, 2);
    addEdge(0, 2, 4);
    addEdge(1, 2, 1);
    addEdge(1, 3, 7);
    addEdge(2, 4, 3);
    addEdge(3, 4, 1);

    dijkstra(V, 0);

    return 0;
}