//题目来自：https://www.nowcoder.com/practice/e3f491c56b7747539b93e5704b6eca40?tpId=46&tqId=29094&rp=4&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
//解法1,两个for循环
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        
        if(height.empty())
            return 0;
        int maxarea = 0;
        for(int i = 0;i < height.size();++i){
            int minhigh = INT_MAX;
            for(int j = i;j < height.size();++j){
                minhigh = min(minhigh,height[j]);
                maxarea = max(maxarea,minhigh*(j-i+1));
            }
        }
        return maxarea;
    }
};

//解法2，用单调递增栈，
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.empty()){
            return 0;
        }
        stack<int> st;
        st.push(-1);
        int maxarea = 0;
        for(int i = 0;i < height.size();++i){
            while(st.top() != -1 && height[st.top()] >= height[i]){//如果当前元素比栈顶元素小，那么就要计算之前的最大面积值。因为此时最大面积不可能出现在栈顶之后。
                int curtop= st.top();
                st.pop();
                maxarea = max(maxarea,height[curtop]*(i-st.top()-1));
            }
            st.push(i);
        }
        //剩余的，或者说是一直递增的，那么按照上面的计算就行了。只是这时的长度是整个数组的长度了。
        int l = height.size();
        while(st.top() != -1){
            int curtop = st.top();
            st.pop();
            maxarea = max(maxarea,height[curtop]*(l-st.top()-1));
        }
        return maxarea;
    }
};

