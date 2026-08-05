class Solution {
public:
    typedef long long ll;
    void bfs(TreeNode* root, int& maxWidth){
       if(root == nullptr) return;
        queue<pair<TreeNode*, long long>> q;
        q.push({root,1});
        while(!q.empty()){
            ll size = q.size();
            ll temp;
            ll first = q.front().second; 
            ll left,right;
            while(size--){
                auto [node,idx] = q.front();
                q.pop();
                idx -= first;
                left = idx * 2;
                right = left + 1; 
                if(node->left != nullptr) q.push({node->left, left});
                if(node->right != nullptr) q.push({node->right, right});
                if(size == 0) temp = idx;
            }
            int width = temp + 1; 
            maxWidth = max(maxWidth, width);
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        bfs(root, maxWidth);
        return maxWidth;
    }
};