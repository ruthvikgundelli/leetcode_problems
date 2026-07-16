class Solution {
public:
    int heightBT(TreeNode* root){
        if(root == nullptr) return 0;
        return 1 + max(heightBT(root->left),heightBT(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int lh,rh;
        lh = heightBT(root->left);
        rh = heightBT(root->right);
        if(abs(lh-rh) > 1) return false;
        bool left,right;
        left = isBalanced(root->left);
        right = isBalanced(root->right);
        if(!left || !right) return false;
        return true;
    }
};