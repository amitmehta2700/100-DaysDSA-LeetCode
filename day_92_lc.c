// Swap function
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition
int partition(int nums[], int left, int right) {
    int pivot = nums[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (nums[j] <= pivot) {
            swap(&nums[i], &nums[j]);
            i++;
        }
    }

    swap(&nums[i], &nums[right]);
    return i;
}

// Quickselect
int quickSelect(int nums[], int left, int right, int k) {
    if (left <= right) {
        int pi = partition(nums, left, right);

        if (pi == k)
            return nums[pi];
        else if (pi < k)
            return quickSelect(nums, pi + 1, right, k);
        else
            return quickSelect(nums, left, pi - 1, k);
    }
    return -1;
}

// LeetCode function
int findKthLargest(int* nums, int numsSize, int k) {
    return quickSelect(nums, 0, numsSize - 1, numsSize - k);
}