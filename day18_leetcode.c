int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    
    *returnSize = numsSize;

    int* answer = (int*)malloc(sizeof(int) * numsSize);

    // Step 1: Store left product in answer[]
    answer[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    // Step 2: Multiply with right product
    int rightProduct = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] = answer[i] * rightProduct;
        rightProduct *= nums[i];
    }

    return answer;
}
