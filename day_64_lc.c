#include <stdlib.h>

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    int queue[100][2];
    int front = 0, rear = 0;

    int fresh = 0;

    // Step 1: Initialize queue and count fresh
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    // If no fresh oranges
    if (fresh == 0) return 0;

    int minutes = 0;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    // BFS
    while (front < rear) {
        int size = rear - front;
        int infected = 0;

        for (int i = 0; i < size; i++) {
            int r = queue[front][0];
            int c = queue[front][1];
            front++;

            for (int d = 0; d < 4; d++) {
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    grid[nr][nc] == 1) {

                    grid[nr][nc] = 2;
                    queue[rear][0] = nr;
                    queue[rear][1] = nc;
                    rear++;

                    fresh--;
                    infected = 1;
                }
            }
        }

        // Only increment time if infection happened
        if (infected) minutes++;
    }

    // If still fresh oranges left → impossible
    return (fresh == 0) ? minutes : -1;
}