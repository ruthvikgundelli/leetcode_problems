class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int zigzag = 0;
        while(!q.empty()){
            int size = q.size();
            TreeNode* node;
            vector<int> temp;
            while(size--){
                node = q.front();
                q.pop();
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                temp.push_back(node->val);
            }
            if(zigzag){
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                zigzag = 0;
            }
            else{
                ans.push_back(temp);
                zigzag = 1;
            }
        } 
        return ans;
    }
};