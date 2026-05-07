#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int* dq = (int*)malloc(sizeof(int) * numsSize); // store indices

    int front = 0, rear = -1;
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {

        // Remove indices out of window
        if (front <= rear && dq[front] <= i - k) {
            front++;
        }

        // Remove smaller elements from rear
        while (front <= rear && nums[dq[rear]] < nums[i]) {
            rear--;
        }

        // Add current index
        dq[++rear] = i;

        // Store result when window is ready
        if (i >= k - 1) {
            result[(*returnSize)++] = nums[dq[front]];
        }
    }

    return result;
}