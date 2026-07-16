class Solution {
public:
    bool isMirror(TreeNode* a, TreeNode* b){
        if(a == nullptr || b == nullptr){
            return a == b;
        }
        else if(a->val != b->val) return false;
        return isMirror(a->left,b->right) && isMirror(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};