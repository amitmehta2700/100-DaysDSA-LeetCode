#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front, rear, size, capacity;
} MyCircularDeque;

// Initialize
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->arr = (int*)malloc(sizeof(int) * k);
    obj->capacity = k;
    obj->front = 0;
    obj->rear = -1;
    obj->size = 0;
    return obj;
}

// Insert at front
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false;

    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->arr[obj->front] = value;
    obj->size++;

    if (obj->size == 1)
        obj->rear = obj->front;

    return true;
}

// Insert at rear
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false;

    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->arr[obj->rear] = value;
    obj->size++;

    if (obj->size == 1)
        obj->front = obj->rear;

    return true;
}

// Delete front
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->size == 0) return false;

    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;

    return true;
}

// Delete rear
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->size == 0) return false;

    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    obj->size--;

    return true;
}

// Get front
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;
    return obj->arr[obj->front];
}

// Get rear
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;
    return obj->arr[obj->rear];
}

// Check empty
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

// Check full
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

// Free memory
void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}