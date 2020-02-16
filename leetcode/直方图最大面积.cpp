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
