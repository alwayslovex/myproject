//求二叉树的最小深度
//使用了层次遍历，当一个节点是叶子节点时返回当前的深度。
class Solution {
public:
    int run(TreeNode *root) {
        if(root == nullptr)
        {
            return 0;
        }
        queue<TreeNode * > que;
        que.push(root);
        int min = 1;
        while(!que.empty())
        {
            int size = que.size();
            for(unsigned i = 0;i < size;++i)
            {
                TreeNode * t;
                t = que.front();
                que.pop();
                if(t->left == nullptr && t->right == nullptr){
                    return min;
                }
                if(t->left != nullptr)
                {
                    que.push(t->left);
                }
                if(t->right != nullptr)
                {
                    que.push(t->right);
                }
            }
            min++;
        }
        return min;
    }
};
