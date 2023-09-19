#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int val) {
    if (root == nullptr) {
        root = new TreeNode(val);
        return;
    }
    
    if (val < root->data)
        insert(root->left, val);
    else
        insert(root->right, val);
}

int main() {
    TreeNode* root = nullptr;
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    
    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);
    
    return 0;
}
