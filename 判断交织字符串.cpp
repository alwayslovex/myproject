class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
        dp[0][0] = 1;
        for(int i = 1;i <= s1.size();++i){
            int r1 = s1.substr(0,i) == s3.substr(0,i) ? 1:0;
            if(dp[i-1][0] == 1 && r1 ==1){
                dp[i][0] = 1;
            }else{
                dp[i][0] = 0;
            }
        }
        for(int j = 1;j <= s2.size();++j){
            dp[0][j] = s2.substr(0,j) == s3.substr(0,j) ? 1:0;
            dp[0][j] = dp[0][j-1] & dp[0][j];
        }
        
        for(int k = 1;k <= s1.size();++k){
            for(int h = 1;h <= s2.size();++h){
                 if(dp[k][h-1] == 1 && s3[k+h-1]==s2[h-1]){
                     dp[k][h] = 1;
                 }else{
                     if(dp[k-1][h] == 1 && s3[k+h-1] == s1[k-1]){
                         dp[k][h] = 1;
                     }
                 }
            }
        }
        return dp[s1.size()][s2.size()] == 1;
    }
};
//动态规划
/*
dp[i][j] 表示s1的前i个字符串，s2的前j个字符串能否构成s3前i+j个字符串
*/
