#include <stdlib.h>

// Find with path compression
int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

// Union
void unionSet(int parent[], int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);
    parent[px] = py;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {

    int parent[1001];

    // Initialize
    for (int i = 1; i <= edgesSize; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        int pu = find(parent, u);
        int pv = find(parent, v);

        // If already connected → cycle
        if (pu == pv) {
            int* res = (int*)malloc(2 * sizeof(int));
            res[0] = u;
            res[1] = v;
            *returnSize = 2;
            return res;
        }

        unionSet(parent, u, v);
    }

    *returnSize = 0;
    return NULL;
}