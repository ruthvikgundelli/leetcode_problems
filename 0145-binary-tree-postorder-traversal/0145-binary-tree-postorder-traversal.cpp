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
    // void postorder(TreeNode* root){
    //     if(root == nullptr) return;
    //     postorder(root->left);
    //     postorder(root->right);
    //     ans.push_back(root->val);
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     ans.clear();
    //     postorder(root);
    //     return ans;
    // }
    vector<int> postorderTraversal(TreeNode* root) {
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
                if(node->right != nullptr) node = node->right;
                else{
                    st.pop();
                    ans.push_back(node->val);
                    while(!st.empty() && node == st.top()->right){
                        node = st.top();
                        st.pop();
                        ans.push_back(node->val);
                    }
                    node = nullptr;
                }
            }
        }
        return ans;
    }
};