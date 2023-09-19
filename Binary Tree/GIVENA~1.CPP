int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumHelper(root, maxSum);
    return maxSum;
}

int maxPathSumHelper(TreeNode* root, int& maxSum) {
    if (root == nullptr)
        return 0;
    
    int leftSum = max(0, maxPathSumHelper(root->left, maxSum));
    int rightSum = max(0, maxPathSumHelper(root->right, maxSum));
    
    maxSum = max(maxSum, leftSum + rightSum + root->data);
    
    return max(leftSum, rightSum) + root->data;
}
