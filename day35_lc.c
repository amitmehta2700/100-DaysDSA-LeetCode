#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int s1[MAX], s2[MAX];
    int top1, top2;
} MyQueue;

// Initialize
MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

// Push (always into stack1)
void myQueuePush(MyQueue* obj, int x) {
    obj->s1[++obj->top1] = x;
}

// Move elements if needed
void transfer(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->s2[++obj->top2] = obj->s1[obj->top1--];
        }
    }
}

// Pop (from stack2)
int myQueuePop(MyQueue* obj) {
    transfer(obj);
    return obj->s2[obj->top2--];
}

// Peek (front element)
int myQueuePeek(MyQueue* obj) {
    transfer(obj);
    return obj->s2[obj->top2];
}

// Check empty
bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

// Free memory
void myQueueFree(MyQueue* obj) {
    free(obj);
}