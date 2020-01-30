/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 给定一个值n,请生成所有的存储值1...n.的二叉搜索树（BST）的结构
递归的方式，从数字中拿取一个作为根，然后比根小的作为左孩子，比根大的作为右孩子，（左孩子递归，右孩子递归）
 */
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<int> numlist;
        if(n==0){
            return vector<TreeNode*>(1,nullptr);
        }
        for(int i =1;i <= n;++i){
            numlist.push_back(i);
        }
        return func(numlist);
    }
    vector<TreeNode *> func(vector<int> list1){
        vector<TreeNode *> res;
        for(int i = 0;i < list1.size();++i){
            //res.push_back(func(numlist,i,list1.size()-1));
            int end = list1.size()-1;
            int t = list1[0];
            list1[0] = list1[i];
            list1[i] = t;
            vector<int> left;
            vector<int> right;
            for(int j = 1;j <= end;++j){
                if(list1[j] < list1[0]){
                    left.push_back(list1[j]);
                }else{
                    right.push_back(list1[j]);
                }
            }
            
            auto lr = func(left);
            auto rr = func(right);
            if(!lr.empty()){
                for(auto jk : lr)
                {
                    if(!rr.empty()){
                        for(auto jk2 : rr){
                            TreeNode * root = new TreeNode(list1[0]);
                            root->left = jk;
                            root->right = jk2;
                            res.push_back(root);
                        } 
                   }else{
                            TreeNode * root = new TreeNode(list1[0]);
                            root->left = jk;
                            res.push_back(root);
                    }
                }
            }else if(!rr.empty()){
                       
                        for(auto jk2 : rr){
                            TreeNode * root = new TreeNode(list1[0]);
                            root->right = jk2;
                            res.push_back(root);
                        } 
            }else{
                TreeNode * root = new TreeNode(list1[0]);
                res.push_back(root);
            }

        }
        
        return res;
    }
};
