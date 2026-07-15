class Solution {
public:
    // vector<int> ans;
    // void inorder(TreeNode* root){
    //     if(root == nullptr) return;
    //     inorder(root->left);
    //     ans.push_back(root->val);
    //     inorder(root->right);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     ans.clear();
    //     inorder(root);
    //     return ans;
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(node != nullptr || !st.empty()){
            if(node != nullptr){
                st.push(node);
                node = node->left;
            }
            else{
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};