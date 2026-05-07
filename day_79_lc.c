#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000000

// adjacency list node
typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* adj[MAX];
Node* rev[MAX];
bool visited[MAX];

int stack[MAX];
int top = -1;

// push to stack
void push(int x) {
    stack[++top] = x;
}

// add edge
void addEdge(Node* graph[], int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

// DFS for ordering
void dfs1(int u) {
    visited[u] = true;

    for (Node* temp = adj[u]; temp; temp = temp->next) {
        if (!visited[temp->v]) {
            dfs1(temp->v);
        }
    }

    push(u);
}

// DFS on reversed graph
void dfs2(int u) {
    visited[u] = true;

    for (Node* temp = rev[u]; temp; temp = temp->next) {
        if (!visited[temp->v]) {
            dfs2(temp->v);
        }
    }
}

int kosaraju(int V) {

    // Step 1: Fill stack
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    // Step 2: Reverse graph
    for (int u = 0; u < V; u++) {
        for (Node* temp = adj[u]; temp; temp = temp->next) {
            addEdge(rev, temp->v, u);
        }
    }

    // reset visited
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Step 3: process stack
    int scc = 0;

    while (top != -1) {
        int u = stack[top--];

        if (!visited[u]) {
            dfs2(u);
            scc++;
        }
    }

    return scc;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        adj[i] = rev[i] = NULL;
        visited[i] = false;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    printf("%d\n", kosaraju(V));

    return 0;
}