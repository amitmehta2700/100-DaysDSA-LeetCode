int maxSubarraySumCircular(int* nums, int numsSize) {

    int totalSum = nums[0];

    int maxSum = nums[0];
    int currMax = nums[0];

    int minSum = nums[0];
    int currMin = nums[0];

    for (int i = 1; i < numsSize; i++) {

        // Kadane for maximum subarray
        currMax = (currMax + nums[i] > nums[i]) ? currMax + nums[i] : nums[i];
        maxSum = (maxSum > currMax) ? maxSum : currMax;

        // Kadane for minimum subarray
        currMin = (currMin + nums[i] < nums[i]) ? currMin + nums[i] : nums[i];
        minSum = (minSum < currMin) ? minSum : currMin;

        totalSum += nums[i];
    }

    // If all elements are negative
    if (totalSum == minSum)
        return maxSum;

    // Return the maximum of normal and circular case
    int circularMax = totalSum - minSum;

    return (maxSum > circularMax) ? maxSum : circularMax;
}
