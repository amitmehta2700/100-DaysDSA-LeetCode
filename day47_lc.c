#include <stdlib.h>

#define MAX 10000

struct TreeNode* queue[MAX];
int front, rear;

void enqueue(struct TreeNode* node) {
    queue[rear++] = node;
}

struct TreeNode* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;

    front = rear = 0;
    enqueue(root);

    int depth = 0;

    while (!isEmpty()) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = dequeue();

            if (curr->left) enqueue(curr->left);
            if (curr->right) enqueue(curr->right);
        }

        depth++;  // one level completed
    }

    return depth;
}