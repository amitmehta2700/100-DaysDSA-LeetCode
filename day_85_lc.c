int findMin(int* nums, int numsSize) {
    int low = 0, high = numsSize - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high]) {
            low = mid + 1;      // min in right
        } else {
            high = mid;         // min in left (including mid)
        }
    }

    return nums[low];
}