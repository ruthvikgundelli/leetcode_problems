class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(root == nullptr) return node;
        TreeNode* prev = nullptr;
        TreeNode* temp = root;
        while(temp){
            prev = temp;
            if(temp->val < val){
                temp = temp->right;
            }
            else temp = temp->left;
        }
        if(prev->val > val){
            prev->left = node;
        }
        else prev->right = node;
        return root;
    }
};