#include <stdlib.h>

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    // Step 1: Frequency map
    int freq[20001] = {0};
    int offset = 10000;

    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + offset]++;
    }

    // Step 2: Count how many numbers exist for each frequency
    int bucketCount[numsSize + 1];
    for (int i = 0; i <= numsSize; i++) bucketCount[i] = 0;

    for (int i = 0; i < 20001; i++) {
        if (freq[i] > 0) {
            bucketCount[freq[i]]++;
        }
    }

    // Step 3: Allocate exact memory for each bucket
    int** bucket = (int**)malloc((numsSize + 1) * sizeof(int*));
    for (int i = 0; i <= numsSize; i++) {
        if (bucketCount[i] > 0)
            bucket[i] = (int*)malloc(bucketCount[i] * sizeof(int));
        else
            bucket[i] = NULL;
    }

    // Step 4: Fill buckets
    int* index = (int*)calloc(numsSize + 1, sizeof(int));

    for (int i = 0; i < 20001; i++) {
        if (freq[i] > 0) {
            int f = freq[i];
            bucket[f][index[f]++] = i - offset;
        }
    }

    // Step 5: Collect result
    int* result = (int*)malloc(k * sizeof(int));
    int count = 0;

    for (int i = numsSize; i >= 0 && count < k; i--) {
        for (int j = 0; j < index[i] && count < k; j++) {
            result[count++] = bucket[i][j];
        }
    }

    *returnSize = k;
    return result;
}