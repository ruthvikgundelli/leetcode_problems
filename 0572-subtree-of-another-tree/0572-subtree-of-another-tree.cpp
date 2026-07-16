class Solution {
public:
    bool isSameTree(TreeNode* a, TreeNode* b){
        if(a == nullptr || b == nullptr){
            return a == b;
        }
        else if(a->val != b->val) return false;
        return isSameTree(a->left,b->left) && isSameTree(a->right,b->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr || subRoot == nullptr){
            return root == subRoot;
        }
        else if(root->val == subRoot->val){
            if(isSameTree(root,subRoot)) return true;
        }
        bool left,right;
        left = isSubtree(root->left,subRoot); 
        right = isSubtree(root->right,subRoot);
        return left || right;
    }
};