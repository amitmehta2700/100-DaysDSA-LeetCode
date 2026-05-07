#include <stdlib.h>

// Comparator for sorting
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place m balls with distance >= d
int canPlace(int* pos, int n, int m, int d) {
    int count = 1;
    int last = pos[0];

    for (int i = 1; i < n; i++) {
        if (pos[i] - last >= d) {
            count++;
            last = pos[i];
        }
        if (count >= m) return 1;
    }

    return 0;
}

int maxDistance(int* position, int positionSize, int m) {
    // Step 1: sort
    qsort(position, positionSize, sizeof(int), cmp);

    int low = 1;
    int high = position[positionSize - 1] - position[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(position, positionSize, m, mid)) {
            ans = mid;         // possible
            low = mid + 1;     // try bigger distance
        } else {
            high = mid - 1;
        }
    }

    return ans;
}