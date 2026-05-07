#include <stdlib.h>

int timer;

void dfs(int u, int parent,
         int** adj, int* adjSize,
         int* disc, int* low,
         int** result, int* returnSize) {

    disc[u] = low[u] = timer++;

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];

        if (v == parent) continue;

        if (disc[v] == -1) {
            dfs(v, u, adj, adjSize, disc, low, result, returnSize);

            if (low[v] < low[u]) low[u] = low[v];

            // Bridge condition
            if (low[v] > disc[u]) {
                result[*returnSize] = (int*)malloc(2 * sizeof(int));
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                (*returnSize)++;
            }
        } else {
            if (disc[v] < low[u]) low[u] = disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                          int* connectionsColSize,
                          int* returnSize,
                          int** returnColumnSizes) {

    // Step 1: Build adjacency list
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));

    // First count degrees
    for (int i = 0; i < connectionsSize; i++) {
        adjSize[connections[i][0]]++;
        adjSize[connections[i][1]]++;
    }

    // Allocate exact memory
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0; // reset
    }

    // Fill adjacency list
    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    // Step 2: Initialize arrays
    int* disc = (int*)malloc(n * sizeof(int));
    int* low  = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        disc[i] = -1;
    }

    int** result = (int**)malloc(connectionsSize * sizeof(int*));
    *returnSize = 0;

    timer = 0;

    // Step 3: DFS
    dfs(0, -1, adj, adjSize, disc, low, result, returnSize);

    // Step 4: Column sizes
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}