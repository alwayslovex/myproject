class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode *root) {
        if(root == nullptr){
            return res;
        }
        if(root->left != nullptr){
            inorderTraversal(root->left);
        }
        res.push_back(root->val);
        if(root->right != nullptr){
            inorderTraversal(root->right);
        }
        return res;
    }
    
};
