bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    // Both NULL → symmetric
    if (left == NULL && right == NULL) return true;

    // One NULL → not symmetric
    if (left == NULL || right == NULL) return false;

    // Values must match + recursive check
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}