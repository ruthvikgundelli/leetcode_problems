class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right)); 
    }
    // int maxDepth(TreeNode* root) {
    //     if(root == nullptr) return 0;
    //     int depth = 0;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         int size = q.size();
    //         while(size--){
    //             auto temp = q.front();
    //             q.pop();
    //             if(temp->left != nullptr) q.push(temp->left);
    //             if(temp->right != nullptr) q.push(temp->right);
    //         }
    //         depth++;
    //     }
    //     return depth;
    // }
};