class Solution {
public:
    map<string,bool> res;
    bool isScramble(string s1, string s2) {
        if(s1 == s2){
            return true;
        }
        int flags = 0;
        for(int i = 0;i < s1.size();++i){
            flags ^= 1<<s1[i]-'a';
            flags ^= 1<<s2[i]-'a';
        }
        if(flags > 0){
                res[s1+s2] = false;
                return false;   
        }
        if(res.find(s1+s2) != res.end()){
            return res[s1+s2];
        }
        
        bool ret = false;
        //真正的递归
        for(int i = 1;i < s1.size();++i){
            //先分割，再交换分割得到
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) &&
              isScramble(s1.substr(i),s2.substr(i))
              ){
                ret = true;
                break;
            }
            
            //先分割，然后交换，然后再交换分割
            if(isScramble(s1.substr(0,i),s2.substr(s2.size()-i)) &&
              isScramble(s1.substr(i),s2.substr(0,s2.size()-i))
              ){
                ret =  true;
                break;
            }
        }
        res[s1+s2] = ret;
        return ret;
    }
};
