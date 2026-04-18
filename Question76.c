#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int *graph[MAXN];
int graphSize[MAXN];
int visited[MAXN];

void addEdge(int u, int v) {
    graph[u] = realloc(graph[u], (graphSize[u] + 1) * sizeof(int));
    graph[u][graphSize[u]++] = v;
}

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < graphSize[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 1; i <= n; i++) {
        graph[i] = NULL;
        graphSize[i] = 0;
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u); // undirected
    }

    int components = 0;

    // Count components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);
    return 0;
}