/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
public:
    // vector<int> ans;
    // void preorder(TreeNode* root){
    //     if(root == nullptr) return;
    //     ans.push_back(root->val);
    //     preorder(root->left);
    //     preorder(root->right);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     ans.clear();
    //     preorder(root);
    //     return ans;
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right != nullptr) st.push(node->right);
            if(node->left != nullptr) st.push(node->left);
        }
        return ans;
    }
};