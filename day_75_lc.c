#include <stdbool.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize) {

    int color[100];

    // Initialize all nodes as uncolored
    for (int i = 0; i < graphSize; i++) {
        color[i] = -1;
    }

    // Check all components
    for (int i = 0; i < graphSize; i++) {

        if (color[i] != -1) continue;

        // BFS queue
        int queue[100];
        int front = 0, rear = 0;

        queue[rear++] = i;
        color[i] = 0;

        while (front < rear) {
            int node = queue[front++];

            for (int j = 0; j < graphColSize[node]; j++) {
                int neighbor = graph[node][j];

                // Not colored
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    queue[rear++] = neighbor;
                }
                // Same color → not bipartite
                else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
    }

    return true;
}