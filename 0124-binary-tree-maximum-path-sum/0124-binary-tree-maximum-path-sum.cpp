class Solution {
public:
    int path(TreeNode* root, int& sum){
        if(root == nullptr) return 0;
        int lh,rh;
        lh = path(root->left, sum);
        rh = path(root->right, sum);
        sum = max(sum, max(root->val, max(lh+root->val, max(rh+root->val, lh+rh+root->val))));
        return max(root->val, max(lh+root->val, rh+root->val));
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        path(root,sum);
        return sum;
    }
};