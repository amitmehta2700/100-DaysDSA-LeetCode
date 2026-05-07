#include <stdlib.h>

int** floodFill(int** image, int m, int* colSize,
                int sr, int sc, int color,
                int* returnSize, int** returnColumnSizes) {

    int n = colSize[0];
    int oldColor = image[sr][sc];

    if (oldColor == color) {
        *returnSize = m;
        *returnColumnSizes = colSize;
        return image;
    }

    int queue[2500][2];
    int front = 0, rear = 0;

    queue[rear][0] = sr;
    queue[rear][1] = sc;
    rear++;

    image[sr][sc] = color;

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (front < rear) {
        int r = queue[front][0];
        int c = queue[front][1];
        front++;

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                image[nr][nc] == oldColor) {

                image[nr][nc] = color;
                queue[rear][0] = nr;
                queue[rear][1] = nc;
                rear++;
            }
        }
    }

    *returnSize = m;
    *returnColumnSizes = colSize;

    return image;
}