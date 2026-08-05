class Solution {
public:
    TreeNode* prev = nullptr;
    bool inorder(TreeNode* node) {
        if (node == nullptr) return true;
        if (!inorder(node->left)) return false;
        if (prev && prev->val >= node->val) return false;
        prev = node;
        if (!inorder(node->right)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }

};