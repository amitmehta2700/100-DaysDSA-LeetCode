#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    
    int* result = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(temperaturesSize * sizeof(int)); // store indices
    
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {
        
        // Resolve previous colder days
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int prevIndex = stack[top--];
            result[prevIndex] = i - prevIndex;
        }
        
        // Push current index
        stack[++top] = i;
    }

    *returnSize = temperaturesSize;
    return result;
}