#include <stdio.h>
#include <stdbool.h>

bool isToeplitz(int matrix[20][20], int m, int n) {
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] != matrix[i-1][j-1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[20][20];

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    if(isToeplitz(matrix, m, n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
