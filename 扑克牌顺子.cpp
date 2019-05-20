/*
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子，“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.决定大\小 王可以看成任何数字,
并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。
现在,要求你使用这幅牌模拟上面的过程,如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0

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
