class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1,0);
        if(n == 0){
            return res;
        }
        res.push_back(1);
        for(int i = 2;i <= n;++i){
            int len = res.size();
            int b = 1<<(i-1);
            for(int j = len-1;j >= 0;--j){
                int t = res[j] | b;
                res.push_back(t);
            }
        }
        return res;
    }
};

//规律如下。
// 0 1
// 0 1 1 0
// 00 01 11 10
// 000 001 011 010 110 111 101 100
