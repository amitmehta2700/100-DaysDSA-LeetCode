#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 26

// adjacency matrix
int graph[MAX][MAX];
int indegree[MAX];

// queue for BFS
int queue[MAX], front = 0, rear = 0;

// enqueue
void push(int x) {
    queue[rear++] = x;
}

// dequeue
int pop() {
    return queue[front++];
}

char* alienOrder(char words[][100], int n) {
    memset(graph, 0, sizeof(graph));
    memset(indegree, 0, sizeof(indegree));

    bool present[MAX] = {false};

    // mark characters present
    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = true;
        }
    }

    // build graph
    for (int i = 0; i < n - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];

        int len1 = strlen(w1);
        int len2 = strlen(w2);

        int found = 0;

        for (int j = 0; j < len1 && j < len2; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                if (!graph[u][v]) {
                    graph[u][v] = 1;
                    indegree[v]++;
                }
                found = 1;
                break;
            }
        }

        // prefix case
        if (!found && len1 > len2) {
            return "";
        }
    }

    // push nodes with indegree 0
    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] == 0) {
            push(i);
        }
    }

    char *result = (char*)malloc(sizeof(char) * 27);
    int idx = 0;

    // Kahn’s Algorithm
    while (front < rear) {
        int u = pop();
        result[idx++] = u + 'a';

        for (int v = 0; v < MAX; v++) {
            if (graph[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    push(v);
                }
            }
        }
    }

    result[idx] = '\0';

    // check cycle
    int total = 0;
    for (int i = 0; i < MAX; i++) {
        if (present[i]) total++;
    }

    if (idx != total) {
        return ""; // cycle exists
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    char words[500][100];

    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    char *ans = alienOrder(words, n);

    if (strlen(ans) == 0)
        printf("\"\n");
    else
        printf("%s\n", ans);

    return 0;
}