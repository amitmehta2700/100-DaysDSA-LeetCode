#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 15

int n;
int cost[MAX][MAX];
int dp[1 << MAX][MAX];

// DP function
int tsp(int mask, int pos) {

    // all cities visited
    if (mask == (1 << n) - 1) {
        return cost[pos][0]; // return to start
    }

    // already computed
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    // try all cities
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {

            int newAns = cost[pos][city] +
                         tsp(mask | (1 << city), city);

            if (newAns < ans)
                ans = newAns;
        }
    }

    return dp[mask][pos] = ans;
}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    memset(dp, -1, sizeof(dp));

    int result = tsp(1, 0); // start from city 0

    printf("%d\n", result);

    return 0;
}