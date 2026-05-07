#include <stdlib.h>
#include <limits.h>

struct Edge {
    int to, cost;
    struct Edge* next;
};

// Add edge
void addEdge(struct Edge** adj, int u, int v, int w) {
    struct Edge* e = (struct Edge*)malloc(sizeof(struct Edge));
    e->to = v;
    e->cost = w;
    e->next = adj[u];
    adj[u] = e;
}

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize,
                      int src, int dst, int k) {

    // Build graph
    struct Edge* adj[100] = {NULL};

    for (int i = 0; i < flightsSize; i++) {
        addEdge(adj, flights[i][0], flights[i][1], flights[i][2]);
    }

    // Distance array
    int dist[100];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    // Queue: node + cost
    int queue[10000][2];
    int front = 0, rear = 0;

    queue[rear][0] = src;
    queue[rear][1] = 0;
    rear++;

    int stops = 0;

    while (front < rear && stops <= k) {
        int size = rear - front;

        // Temp array to avoid overwriting
        int tempDist[100];
        for (int i = 0; i < n; i++) tempDist[i] = dist[i];

        for (int i = 0; i < size; i++) {
            int node = queue[front][0];
            int cost = queue[front][1];
            front++;

            struct Edge* temp = adj[node];

            while (temp) {
                int next = temp->to;
                int newCost = cost + temp->cost;

                if (newCost < tempDist[next]) {
                    tempDist[next] = newCost;
                    queue[rear][0] = next;
                    queue[rear][1] = newCost;
                    rear++;
                }

                temp = temp->next;
            }
        }

        // Copy back
        for (int i = 0; i < n; i++) dist[i] = tempDist[i];

        stops++;
    }

    return (dist[dst] == INT_MAX) ? -1 : dist[dst];
}