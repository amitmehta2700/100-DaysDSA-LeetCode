#include <stdlib.h>

#define MAX 50000

typedef struct {
    int maxHeap[MAX]; // left (smaller half)
    int minHeap[MAX]; // right (larger half)
    int maxSize;
    int minSize;
} MedianFinder;

// ---------- Max Heap ----------
void maxHeapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] >= heap[index]) break;
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
        index = parent;
    }
}

void maxHeapifyDown(int* heap, int size, int index) {
    while (2 * index + 1 < size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = left;

        if (right < size && heap[right] > heap[left])
            largest = right;

        if (heap[index] >= heap[largest]) break;

        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;

        index = largest;
    }
}

// ---------- Min Heap ----------
void minHeapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= heap[index]) break;
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
        index = parent;
    }
}

void minHeapifyDown(int* heap, int size, int index) {
    while (2 * index + 1 < size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = left;

        if (right < size && heap[right] < heap[left])
            smallest = right;

        if (heap[index] <= heap[smallest]) break;

        int temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;

        index = smallest;
    }
}

// ---------- Core Functions ----------

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void addNum(MedianFinder* obj, int num) {
    
    // Step 1: Add to max heap
    obj->maxHeap[obj->maxSize++] = num;
    maxHeapifyUp(obj->maxHeap, obj->maxSize - 1);

    // Step 2: Balance: move top to min heap
    int top = obj->maxHeap[0];
    obj->maxHeap[0] = obj->maxHeap[--obj->maxSize];
    maxHeapifyDown(obj->maxHeap, obj->maxSize, 0);

    obj->minHeap[obj->minSize++] = top;
    minHeapifyUp(obj->minHeap, obj->minSize - 1);

    // Step 3: Ensure size condition
    if (obj->minSize > obj->maxSize) {
        int minTop = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[--obj->minSize];
        minHeapifyDown(obj->minHeap, obj->minSize, 0);

        obj->maxHeap[obj->maxSize++] = minTop;
        maxHeapifyUp(obj->maxHeap, obj->maxSize - 1);
    }
}

double findMedian(MedianFinder* obj) {
    if (obj->maxSize > obj->minSize) {
        return obj->maxHeap[0];
    }
    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}