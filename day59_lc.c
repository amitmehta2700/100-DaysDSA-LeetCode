#include <stdlib.h>

// Create node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Recursive builder
struct TreeNode* build(int* postorder, int* postIndex,
                       int inStart, int inEnd,
                       int* indexMap) {
    
    if (inStart > inEnd) return NULL;

    // Pick root from postorder
    int rootVal = postorder[(*postIndex)--];
    struct TreeNode* root = createNode(rootVal);

    int inIndex = indexMap[rootVal + 3000];

    // Build RIGHT first (important!)
    root->right = build(postorder, postIndex, inIndex + 1, inEnd, indexMap);
    root->left  = build(postorder, postIndex, inStart, inIndex - 1, indexMap);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize,
                           int* postorder, int postorderSize) {

    // Map value → index
    int* indexMap = (int*)malloc(6001 * sizeof(int));
    for (int i = 0; i < inorderSize; i++) {
        indexMap[inorder[i] + 3000] = i;
    }

    int postIndex = postorderSize - 1;

    return build(postorder, &postIndex, 0, inorderSize - 1, indexMap);
}