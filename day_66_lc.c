#include <stdlib.h>
#include <stdbool.h>

// DFS to detect cycle
bool dfs(int node, int** adj, int* adjSize, int* state) {
    if (state[node] == 1) return true;  // cycle found
    if (state[node] == 2) return false; // already processed

    state[node] = 1; // mark as visiting

    for (int i = 0; i < adjSize[node]; i++) {
        int next = adj[node][i];
        if (dfs(next, adj, adjSize, state))
            return true;
    }

    state[node] = 2; // mark as done
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    // Build adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int)); // max possible
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a; // b → a
    }

    int* state = (int*)calloc(numCourses, sizeof(int));

    // Check each node
    for (int i = 0; i < numCourses; i++) {
        if (dfs(i, adj, adjSize, state))
            return false;
    }

    return true;
}