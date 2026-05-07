#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;

// Swap
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify up
void heapifyUp(KthLargest* obj, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (obj->heap[p] > obj->heap[i]) {
            swap(&obj->heap[p], &obj->heap[i]);
            i = p;
        } else break;
    }
}

// Heapify down
void heapifyDown(KthLargest* obj, int i) {
    while (1) {
        int smallest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < obj->size && obj->heap[l] < obj->heap[smallest])
            smallest = l;
        if (r < obj->size && obj->heap[r] < obj->heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(&obj->heap[i], &obj->heap[smallest]);
            i = smallest;
        } else break;
    }
}

// Initialize
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = malloc(sizeof(KthLargest));
    obj->heap = malloc(sizeof(int) * k); // ✅ ONLY k size
    obj->size = 0;
    obj->k = k;

    for (int i = 0; i < numsSize; i++) {
        // reuse add logic
        if (obj->size < k) {
            obj->heap[obj->size] = nums[i];
            heapifyUp(obj, obj->size);
            obj->size++;
        } else if (nums[i] > obj->heap[0]) {
            obj->heap[0] = nums[i];
            heapifyDown(obj, 0);
        }
    }

    return obj;
}

// Add element
int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size] = val;
        heapifyUp(obj, obj->size);
        obj->size++;
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }

    return obj->heap[0]; // kth largest
}

// Free
void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}