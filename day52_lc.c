struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // Base case
    if (root == NULL || root == p || root == q) {
        return root;
    }

    // Search in left and right
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both sides return non-NULL → this is LCA
    if (left != NULL && right != NULL) {
        return root;
    }

    // Otherwise return the non-NULL side
    return (left != NULL) ? left : right;
}