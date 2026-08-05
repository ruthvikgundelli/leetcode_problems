// class Solution {
// public:
//     TreeNode* search(TreeNode* root, int key){
//         if(root == nullptr) return nullptr;
//         TreeNode* parent = nullptr;
//         while(root && root->val != key){
//             parent = root;
//             if(key < root->val){
//                 root = root->left;
//             }
//             else{
//                 root = root->right;
//             }
//         }
//         if(root == nullptr) return nullptr;
//         return parent;
//     }
//     void modify(TreeNode* parent, TreeNode* del, string direction){
//         // deleted node has no left child
//         if(del->left == nullptr){
//             if(direction == "left"){
//                 parent->left = del->right;
//             }
//             else{
//                 parent->right = del->right;
//             }
//             delete del;
//             return;
//         }
//         TreeNode* node = del->left;
//         if(direction == "left"){
//             parent->left = node;
//         }
//         else{
//             parent->right = node;
//         }
//         while(node->right){
//             node = node->right;
//         }
//         node->right = del->right;
//         delete del;
//     }
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root == nullptr) return nullptr;
//         // deleting root
//         if(root->val == key){
//             if(root->left == nullptr){
//                 TreeNode* temp = root->right;
//                 delete root;
//                 return temp;
//             }
//             TreeNode* newRoot = root->left;
//             TreeNode* node = newRoot;
//             while(node->right){
//                 node = node->right;
//             }
//             node->right = root->right;
//             delete root;
//             return newRoot;
//         }
//         TreeNode* parent = search(root, key);
//         // key doesn't exist
//         if(parent == nullptr){
//             return root;
//         }
//         if(parent->left && parent->left->val == key){
//             modify(parent, parent->left, "left");
//         }
//         else if(parent->right && parent->right->val == key){
//             modify(parent, parent->right, "right");
//         }
//         return root;
//     }
// };
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val == key) {
            return helper(root);
        }

        TreeNode* dummy = root;

        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }
            else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }

    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL) {
            return root->right;
        }
        else if (root->right == NULL) {
            return root->left;
        }

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);

        lastRight->right = rightChild;

        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }

        return findLastRight(root->right);
    }
};