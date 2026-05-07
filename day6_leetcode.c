#include <stdio.h>

int main() {
    int m, n;

    // Input rows and columns
    scanf("%d %d", &m, &n);

    int a[m][n], b[m][n];

    // Input first matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input second matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Add and print matrix directly
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d", a[i][j] + b[i][j]);
            if(j != n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
