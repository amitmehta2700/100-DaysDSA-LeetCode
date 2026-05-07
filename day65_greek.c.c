#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100005

int adj[MAX][MAX];   // adjacency matrix (not optimal for large constraints but okay for concept)
bool visited[MAX];
int V;

// DFS function to detect cycle
bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {  // if edge exists
            if (!visited[i]) {
                if (dfs(i, node))
                    return true;
            }
            else if (i != parent) {
                return true;  // cycle detected
            }
        }
    }
    return false;
}

// Function to check cycle in all components
bool hasCycle() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int E;
    scanf("%d %d", &V, &E);

    // initialize adjacency matrix
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    }

    // input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    if (hasCycle())
        printf("true\n");
    else
        printf("false\n");

    return 0;
}