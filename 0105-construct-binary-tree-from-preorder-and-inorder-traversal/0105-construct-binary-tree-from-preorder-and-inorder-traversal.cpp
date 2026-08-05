class Solution {
public:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int,int>& mp){
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int idx = mp[root->val];
        int leftSize = idx - inStart;

        root->left = build(preorder, preStart+1, preStart + leftSize,
                            inorder, inStart, idx-1, mp);
        root->right = build(preorder, preStart + leftSize + 1, preEnd,
                            inorder, idx + 1, inEnd, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};