class Solution {
public:
    // int maxDepth(TreeNode* root) {
    //     if (root == nullptr) return 0;
    //     return 1 + max(maxDepth(root->left),maxDepth(root->right)); 
    // }
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int depth = 0;
        queue<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            int size = st.size();
            while(size--){
                auto temp = st.front();
                st.pop();
                if(temp->left != nullptr) st.push(temp->left);
                if(temp->right != nullptr) st.push(temp->right);
            }
            depth++;
        }
        return depth;
    }
};