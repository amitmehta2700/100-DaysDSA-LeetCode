#include <stdlib.h>

// Helper to create node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree recursively
struct TreeNode* build(int* preorder, int preStart, int preEnd,
                       int* inorder, int inStart, int inEnd,
                       int* indexMap) {
    
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    // Root from preorder
    int rootVal = preorder[preStart];
    struct TreeNode* root = createNode(rootVal);

    // Find root index in inorder
    int inIndex = indexMap[rootVal + 3000]; // offset for negative values

    int leftSize = inIndex - inStart;

    // Build left and right
    root->left = build(preorder, preStart + 1, preStart + leftSize,
                       inorder, inStart, inIndex - 1, indexMap);

    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                        inorder, inIndex + 1, inEnd, indexMap);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    // Map value → index
    int* indexMap = (int*)malloc(6001 * sizeof(int));

    for (int i = 0; i < inorderSize; i++) {
        indexMap[inorder[i] + 3000] = i;
    }

    return build(preorder, 0, preorderSize - 1,
                 inorder, 0, inorderSize - 1,
                 indexMap);
}