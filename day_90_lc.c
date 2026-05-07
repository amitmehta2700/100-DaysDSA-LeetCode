#include <stdio.h>

// Helper function to check if we can split into <= k subarrays
int canSplit(int* nums, int n, int k, long long maxSum) {
    int count = 1;
    long long currSum = 0;

    for (int i = 0; i < n; i++) {
        if (currSum + nums[i] <= maxSum) {
            currSum += nums[i];
        } else {
            count++;
            currSum = nums[i];
        }
    }

    return count <= k;
}

int splitArray(int* nums, int numsSize, int k) {
    long long left = nums[0], right = 0;

    // Find max element and total sum
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > left)
            left = nums[i];
        right += nums[i];
    }

    long long ans = right;

    // Binary search
    while (left <= right) {
        long long mid = (left + right) / 2;

        if (canSplit(nums, numsSize, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return (int)ans;
}