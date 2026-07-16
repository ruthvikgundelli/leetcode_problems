class Solution {
public:
    int height(TreeNode* root, int& length){
        if(root == nullptr) return 0;
        int lh,rh;
        lh = height(root->left, length);
        rh = height(root->right, length);
        length = max(length, lh+rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int length = 0;
        height(root,length);
        return length;
    }
};