class Solution {
public:
    // bool dfs(TreeNode* node, vector<TreeNode*>& path, TreeNode* x){
    //     if(node == nullptr) return false;
    //     path.push_back(node);
    //     if(node == x) return true;
    //     if(dfs(node->left, path, x) || dfs(node->right, path, x)) return true;
    //     path.pop_back();
    //     return false;
    // }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if(root == nullptr) return nullptr;
    //     vector<TreeNode*> p_path, q_path;
    //     dfs(root, p_path, p);
    //     dfs(root, q_path, q);
    //     TreeNode* ans;
    //     int P = 0, Q = 0;
    //     while(P < p_path.size() && Q < q_path.size()){
    //         if(p_path[P] != q_path[Q]){
    //             break;
    //         }
    //         ans = p_path[P];
    //         P++;
    //         Q++;
    //     }
    //     return ans;
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // TC - O(N), SC - O(H)
        if(root == nullptr || p == root || q == root) return root;
        TreeNode *left, *right;
        left = lowestCommonAncestor(root->left, p, q);
        right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr) return root;
        return left ? left : right;
    }
};