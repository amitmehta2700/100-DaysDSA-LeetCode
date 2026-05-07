#include <stdlib.h>
#include <limits.h>

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {

    int n = pointsSize;

    int minDist[1000];
    int visited[1000] = {0};

    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
    }

    minDist[0] = 0; // start from point 0

    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        // Pick minimum distance node
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalCost += minDist[u];

        // Update distances
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int cost = abs(points[u][0] - points[v][0]) +
                           abs(points[u][1] - points[v][1]);

                if (cost < minDist[v]) {
                    minDist[v] = cost;
                }
            }
        }
    }

    return totalCost;
}