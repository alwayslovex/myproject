/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度,只有根节点则为0
层次遍历，深度其实就是层数
*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        queue<TreeNode * > qu;
        if(pRoot == nullptr)
        {
            return 0;
        }
        qu.push(pRoot);
        int i = -1;
        while(!qu.empty())
        {
            ++i;
            size_t size = qu.size();
            for(int j =0;j < size;++j)
            {
                TreeNode * t;
                t = qu.front();
                qu.pop();
                if(t == nullptr)
                {
                    continue;
                }
                qu.push(t->left);
                qu.push(t->right);
            }
        }
        
        return i;
    }
};
