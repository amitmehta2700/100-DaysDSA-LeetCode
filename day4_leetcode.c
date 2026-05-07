
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int n = numsSize; // use a separate variable to track the current effective length

    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1]; // replace with last element
            --n;                    // shrink effective length
        } else {
            ++i;                    // keep element, move forward
        }
    }

    return n;
}
