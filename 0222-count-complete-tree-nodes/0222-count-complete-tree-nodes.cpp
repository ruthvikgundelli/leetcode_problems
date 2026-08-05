class Solution {
public:
    pair<bool,int> checkPerfect(TreeNode* node){
        int leftH = 0, rightH = 0;
        TreeNode* nodeL = node;
        TreeNode* nodeR = node;
        while(nodeL){
            leftH++;
            nodeL = nodeL->left;
        }
        while(nodeR){
            rightH++;
            nodeR = nodeR->right;
        }
        if(leftH == rightH) return {true,rightH};
        return {false,leftH};
    }
    // int countNodes(TreeNode* root) {
    //     if(root == nullptr) return 0;
    //     auto [check, h] = checkPerfect(root);
    //     if(check){
    //         return (1 << h) - 1;
    //     }
    //     return 1 + countNodes(root->left) + countNodes(root->right);
    // }
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        TreeNode* node = root;
        stack<TreeNode*> st;
        st.push(node);
        int ans = 0;
        while(!st.empty()){
            node = st.top();
            st.pop();
            auto [check, h] = checkPerfect(node);
            if(check) ans += (1 << h);
            else{
                st.push(node->left);
                st.push(node->right);
            }
        }
        return ans - 1;
    }
};