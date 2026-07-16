class Solution {
public:
    bool isSame(TreeNode* a, TreeNode* b){
        if(a == nullptr || b == nullptr){
            return a == b;
        }
        else if(a->val != b->val) return false;
        return isSame(a->left,b->right) && isSame(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left, root->right);
    }
};