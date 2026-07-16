class Solution {
public:
    // TreeNode* invertTree(TreeNode* root) {
    //     if(root == nullptr) return nullptr;
    //     stack<TreeNode*> st;
    //     st.push(root);
    //     while(!st.empty()){
    //         TreeNode* node = st.top();
    //         st.pop();
    //         if(node->left != nullptr) st.push(node->left);
    //         if(node->right != nullptr) st.push(node->right);
    //         swap(node->left, node->right);
    //     }
    //     return root;
    // }
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};