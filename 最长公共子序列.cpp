class LCS {
public:
    //
    int findLCS(string A, int n, string B, int m) {
        // write code here
        vector<int> t(m+1,0);
        vector<vector<int> > ar(n+1,t);
        for(int i =1;i <= n;++i)
        {
            for(int j = 1;j <= m;++j)
            {
                if(i == 0 || j == 0)
                {
                    ar[i][j] = 0;
                }
                else if(A[i-1] == B[j-1])
                {
                    ar[i][j] = ar[i-1][j-1]+ 1;
                }
                else
                {
                 ar[i][j] = ar[i][j-1] > ar[i-1][j] ? ar[i][j-1]:ar[i-1][j];
                }
            }
        }
        return ar[n][m];
    }
    
};
// 最长公共子序列，就是A:a1 a2 a3 a4 a5...an
//B:b1 b2 b3 b4...bm
//公共子序列为：c1 c2 c3 ...ck
//那么如果an = bm  ck = an=bm
//否则如果ck = bm 则最长在，an-1 和bm中
//0,n-1,n
