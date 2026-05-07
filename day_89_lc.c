int canShip(int* weights, int n, int cap) {
    int days = 1;
    int current = 0;

    for (int i = 0; i < n; i++) {
        if (current + weights[i] <= cap) {
            current += weights[i];
        } else {
            days++;
            current = weights[i];
        }
    }

    return days;
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int low = 0, high = 0;

    // find range
    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > low)
            low = weights[i];   // max element
        high += weights[i];     // total sum
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canShip(weights, weightsSize, mid) <= days) {
            ans = mid;
            high = mid - 1;   // try smaller capacity
        } else {
            low = mid + 1;    // need bigger capacity
        }
    }

    return ans;
}