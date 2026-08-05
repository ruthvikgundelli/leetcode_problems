class Solution {
public:
    // vector<int> ans;
    // void inorder(TreeNode* root){
    //     if(root == nullptr) return;
    //     inorder(root->left);
    //     ans.push_back(root->val);
    //     inorder(root->right);
    // }
    // vector<int> inorderTraversal(TreeNode* root) { // Recursive
    //     ans.clear();
    //     inorder(root);
    //     return ans;
    // }
    // vector<int> inorderTraversal(TreeNode* root) { // Iterative
    //     if(root == nullptr) return {};
    //     vector<int> ans;
    //     stack<TreeNode*> st;
    //     TreeNode* node = root;
    //     while(node != nullptr || !st.empty()){
    //         if(node != nullptr){
    //             st.push(node);
    //             node = node->left;
    //         }
    //         else{
    //             node = st.top();
    //             st.pop();
    //             ans.push_back(node->val);
    //             node = node->right;
    //         }
    //     }
    //     return ans;
    // }
    vector<int> inorderTraversal(TreeNode* root) { // Morris Traversal
        if(root == nullptr) return {};
        vector<int> ans;
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* node = curr->left;
                bool check = true;
                while(node->right){
                    if(node->right == curr){
                        node->right = nullptr;
                        ans.push_back(curr->val);
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
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};