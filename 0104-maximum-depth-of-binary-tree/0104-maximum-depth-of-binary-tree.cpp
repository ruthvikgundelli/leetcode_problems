class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int depth = 1;
        queue<pair<TreeNode*,int>> st;
        st.push({root,depth});
        while(!st.empty()){
            int size = st.size();
            while(size--){
                auto temp = st.front();
                st.pop();
                depth = temp.second;
                if(temp.first->left != nullptr) st.push({temp.first->left,depth+1});
                if(temp.first->right != nullptr) st.push({temp.first->right,depth+1});
            }
        }
        return depth;
    }
};