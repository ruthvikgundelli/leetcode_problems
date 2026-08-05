class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = root;
        if(node == nullptr) return nullptr;
        int value = node->val;
        while(node && value != val){
            if(val < value) node = node->left;
            else node = node->right;
            if(node) value = node->val;
        }
        return node;
    }
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     if(root == nullptr) return nullptr;
    //     if(root->val == val) return root;
    //     else if(val < root->val) return searchBST(root->left,val);
    //     return searchBST(root->right,val);
    // }
};