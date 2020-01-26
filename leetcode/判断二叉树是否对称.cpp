
/*
采用递归的方式。
*/
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == nullptr){
            return true;
        }
        return IsImage(root->left,root->right);
    }
    bool IsImage(TreeNode * left,TreeNode * right){
        if(left == nullptr && right == nullptr){
            return true;
        }
        if(left != nullptr && right != nullptr){
            if(left->val != right->val){
                return false;
            }
            return IsImage(left->left,right->right) && IsImage(left->right,right->left);
        }
        return false;
    }
};
