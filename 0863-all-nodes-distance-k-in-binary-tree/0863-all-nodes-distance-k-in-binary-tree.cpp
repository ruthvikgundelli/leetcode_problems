// class Solution {
// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         queue<TreeNode*> q;
//         unordered_map<TreeNode*, TreeNode*> parent;
//         q.push(root);
//         parent[root] = nullptr;
//         while(!q.empty()){
//             int size = q.size();
//             while(size--){
//                 TreeNode* node = q.front();
//                 q.pop();
//                 if(node->left){
//                     q.push(node->left);
//                     parent[node->left] = node;
//                 }
//                 if(node->right){
//                     q.push(node->right);
//                     parent[node->right] = node;
//                 }
//             }
//         }

//         vector<int> ans;
//         vector<bool> visited(501, false);
//         int dist = 0;
//         q.push(target);
//         visited[target->val] = true;
//         while(!q.empty() && dist < k){
//             dist++;
//             int size = q.size();
//             while(size--){
//                 TreeNode* node = q.front();
//                 q.pop();
//                 if(node->left && !visited[node->left->val]){
//                     q.push(node->left);
//                     visited[node->left->val] = true;
//                 }
//                 if(node->right && !visited[node->right->val]){
//                     q.push(node->right);
//                     visited[node->right->val] = true;
//                 }
//                 if(parent[node] && !visited[parent[node]->val]){
//                     q.push(parent[node]);
//                     visited[parent[node]->val] = true;
//                 }
//             }
//         }
//         while(!q.empty()){
//             ans.push_back(q.front()->val);
//             q.pop();
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> parent;
        q.push(root);
        parent[root] = nullptr;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;
            }
        }
        
        vector<int> ans;
        unordered_set<TreeNode*> visited;
        int dist = 0;
        q.push(target);
        visited.insert(target);
        while(!q.empty() && dist < k){
            dist++;
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parent[node] && !visited.count(parent[node])){
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};