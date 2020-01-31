class Solution {
public:
    int numTrees(int n) {
        vector<int> res;
        for(int i = 1;i <= n;++i){
            res.push_back(i);
        }
        return NumTrees(res);
    }
    int NumTrees(vector<int> &num){
        //取一个，划分左右，进行递归。
        int res = 0;
        for(int i = 0;i < num.size();++i){
            auto t = num[0];
            num[0] = num[i];
            num[i] = t;
            vector<int> left;
            vector<int> right;
            for(auto i = 1;i < num.size();++i){
                if(num[i] < num[0]){
                    left.push_back(num[i]);
                }else{
                    right.push_back(num[i]);
                }
            }
            
            int ll = NumTrees(left);
            int rr = NumTrees(right);
            if(ll > 0 && rr > 0){
                res += ll*rr;
            }else{
                res += ll > 0?ll:rr;
            }
            if(res == 0){
                res = 1;
            }
        }
        return res;
    }
};
