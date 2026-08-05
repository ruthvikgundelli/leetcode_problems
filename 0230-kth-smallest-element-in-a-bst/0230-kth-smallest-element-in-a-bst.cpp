class Solution {
public:
    // int n;
    // void inorder(TreeNode* node, int& ans){
    //     if(node == nullptr) return;
    //     inorder(node->left,ans);
    //     n--;
    //     if(n == 0){
    //         ans = node->val;
    //         return;
    //     }
    //     if(n < 0) return;
    //     inorder(node->right,ans);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     int ans = root->val;
    //     n = k;
    //     inorder(root,ans);
    //     return ans;
    // }
    int kthSmallest(TreeNode* root, int k) {
        int ans = root->val;
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* node = curr->left;
                bool check = true;
                while(node->right){
                    if(node->right == curr){
                        node->right = nullptr;
                        if(k == 1) ans = curr->val;
                        k--;
                        curr = curr->right;
                        check = false;
                        break;
                    }
                    node = node->right;
                }
                if(check){
                    node->right = curr;
                    curr = curr->left;
                }
            }
            else{
                if(k==1)ans = curr->val;
                k--;
                curr = curr->right;
            }
        }
        return ans;
    }
};