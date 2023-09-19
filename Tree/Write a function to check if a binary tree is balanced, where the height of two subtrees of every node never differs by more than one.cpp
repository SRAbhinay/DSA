bool isBalanced(TreeNode* root) {
    if (root == nullptr)
        return true;
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    if (abs(leftHeight - rightHeight) > 1)
        return false;
    
    return isBalanced(root->left) && isBalanced(root->right);
}

int getHeight(TreeNode* node) {
    if (node == nullptr)
        return 0;
    
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    
    return 1 + std::max(leftHeight, rightHeight);
}
