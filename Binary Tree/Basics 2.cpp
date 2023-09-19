#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr)
        return root;
    
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

TreeNode* findMin(TreeNode* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    
    std::cout << "Preorder Traversal before deletion: ";
    preorderTraversal(root);
    
    root = deleteNode(root, 3);
    
    std::cout << "\nPreorder Traversal after deletion: ";
    preorderTraversal(root);
    
    return 0;
}
