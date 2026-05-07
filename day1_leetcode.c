#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Hash table using arrays
    int hashSize = 20001;              // range -10000 to +10000
    int offset = 10000;
    
    int *hash = (int*)malloc(sizeof(int) * hashSize);
    
    // Initialize hash table
    for (int i = 0; i < hashSize; i++) {
        hash[i] = -1;
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        // Check if complement exists
        if (complement >= -10000 && complement <= 10000) {
            int index = hash[complement + offset];
            if (index != -1) {
                int* result = (int*)malloc(sizeof(int) * 2);
                result[0] = index;
                result[1] = i;
                *returnSize = 2;
                free(hash);
                return result;
            }
        }
        
        // Store current number index
        if (nums[i] >= -10000 && nums[i] <= 10000) {
            hash[nums[i] + offset] = i;
        }
    }

    *returnSize = 0;
    free(hash);
    return NULL;
}