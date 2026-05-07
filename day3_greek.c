#include <stdio.h>

int missingNumber(int arr[], int size) {
    int n = size + 1;  // because one number is missing
    
    long long expectedSum = (long long)n * (n + 1) / 2;
    long long actualSum = 0;
    
    for(int i = 0; i < size; i++) {
        actualSum += arr[i];
    }
    
    return (int)(expectedSum - actualSum);
}

int main() {
    int arr[] = {1, 2, 3, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Missing number: %d", missingNumber(arr, size));
}