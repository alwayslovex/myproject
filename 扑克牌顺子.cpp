/*
先排序，然后就好进行计算。
注意空的判断。
*/

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int uni = 0;
        int last = -1;
        if(numbers.empty()){
            return false;
        }
        sort(numbers.begin(),numbers.end(),less<int>());
        
        for(int i = 0;i < numbers.size();++i)
        {
            if(numbers[i] == 0)
            {
                uni +=1;
                continue;
            }
            if(uni > 4)
            {
                return false;
            }
            if(last == -1)
            {
                last = numbers[i];
                continue;
            }
            int dis = numbers[i]-last;
            if(dis == 1)
            {
                last = numbers[i];
                continue;
            }
            else if(uni <= 0){
                return false;
            }else {
                if(dis > 0 )
                {
                    uni -= 1;
                    last += 1;
                    i--;
                }
                else{
                    return false;
                }
            }
        }
        
        return true;
        
    }
};
//0 0 0 1 1
//0 0 1 3 5
