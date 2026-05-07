#include <stdlib.h>

#define MAX 2000

struct TreeNode* queue[MAX];
int front, rear;

void enqueue(struct TreeNode* node) {
    queue[rear % MAX] = node;
    rear++;
}

struct TreeNode* dequeue() {
    struct TreeNode* node = queue[front % MAX];
    front++;
    return node;
}

int isEmpty() {
    return front == rear;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
    front = rear = 0;   // 🔥 IMPORTANT FIX

    int** result = (int**)malloc(sizeof(int*) * MAX);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAX);
    *returnSize = 0;

    if (root == NULL) return result;

    enqueue(root);

    while (!isEmpty()) {
        int levelSize = rear - front;

        result[*returnSize] = (int*)malloc(sizeof(int) * levelSize);
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* curr = dequeue();

            result[*returnSize][i] = curr->val;

            if (curr->left) enqueue(curr->left);
            if (curr->right) enqueue(curr->right);
        }

        (*returnSize)++;
    }

    return result;
}