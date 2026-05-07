#include <stdlib.h>

void preorder(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;

    result[(*returnSize)++] = root->val;  // Root
    preorder(root->left, result, returnSize);  // Left
    preorder(root->right, result, returnSize); // Right
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;

    preorder(root, result, returnSize);

    return result;
}