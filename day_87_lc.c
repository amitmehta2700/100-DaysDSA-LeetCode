#include <limits.h>

// Helper: check if speed k works
long long canEat(int* piles, int n, int k) {
    long long hours = 0;

    for (int i = 0; i < n; i++) {
        hours += (piles[i] + k - 1) / k; // ceil division
    }

    return hours;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1;
    int high = 0;

    // find max pile
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > high)
            high = piles[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canEat(piles, pilesSize, mid) <= h) {
            ans = mid;
            high = mid - 1;  // try smaller speed
        } else {
            low = mid + 1;   // need faster
        }
    }

    return ans;
}