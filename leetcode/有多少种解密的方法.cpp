class Solution {
public:
    map<string,int> tmp;//用来进行缓存
    int numDecodings(string s) {
        int res = 0;
        if(s.empty() || s[0]=='0'){//0开头的都是不能解密的
            return res;
        }
        if(s.size() == 1){
            return 1;
        }
        if(tmp.find(s) != tmp.end()){
            return tmp[s];
        }
        string sub1 = s.substr(1,s.size()-1);
        string sub2 = s.substr(2,s.size()-2);
        string sub3 = s.substr(0,2);
        res += numDecodings(sub1);
        if(s.size() >= 2 && sub3 <= "26"){
           if(s.size() == 2){
               res += 1;
           }else{
               res += numDecodings(sub2);
           }
        }
        tmp[s] = res;
        return res;
    }
};

/*
一条仅包含字母‘A’-‘Z’的消息用下列的方式加密成数字
'A' -> 1↵'B' -> 2↵...↵'Z' -> 26
现在给出加密成数字的密文，请判断有多少种解密的方法
例如：
给出的密文为“12”，可以解密为"AB"(1 2) 或者"L"(12).
所以密文"12"的解密方法是2种.
*/
