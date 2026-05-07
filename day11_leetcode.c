#include <stdio.h>

int main() {
    int m, n;

    // Input rows and columns
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int transpose[n][m];

    // Input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Compute transpose
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print transpose
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d", transpose[i][j]);
            if(j < m - 1)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
