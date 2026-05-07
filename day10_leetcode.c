#include <stdio.h>

int main() {
    int n1, n2;

    // Input sizes
    scanf("%d", &n1);
    int nums1[n1];

    for(int i = 0; i < n1; i++)
        scanf("%d", &nums1[i]);

    scanf("%d", &n2);
    int nums2[n2];

    for(int i = 0; i < n2; i++)
        scanf("%d", &nums2[i]);

    int freq[1001] = {0};

    // Count elements of nums1
    for(int i = 0; i < n1; i++)
        freq[nums1[i]]++;

    int result[1000]; // max possible intersection
    int k = 0;

    // Find intersection
    for(int i = 0; i < n2; i++) {
        if(freq[nums2[i]] > 0) {
            result[k++] = nums2[i];
            freq[nums2[i]]--;
        }
    }

    // Print result
    for(int i = 0; i < k; i++) {
        printf("%d", result[i]);
        if(i < k-1)
            printf(" ");
    }

    return 0;
}
