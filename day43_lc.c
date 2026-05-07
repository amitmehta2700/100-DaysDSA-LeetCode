#include <stdlib.h>

#define MAX 100

// Stack
struct TreeNode* stack[MAX];
int top = -1;

void push(struct TreeNode* node) {
    stack[++top] = node;
}

struct TreeNode* pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * MAX);
    *returnSize = 0;

    struct TreeNode* curr = root;

    while (curr != NULL || !isEmpty()) {

        while (curr != NULL) {
            push(curr);
            curr = curr->left;
        }

        curr = pop();
        result[(*returnSize)++] = curr->val;

        curr = curr->right;
    }

    return result;
}