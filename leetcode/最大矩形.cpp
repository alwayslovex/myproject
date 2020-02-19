//给出一个只包含0和1的二维矩阵，找出最大的全部元素都是1的长方形区域，返回该区域的面积。
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()){
            return 0;
        }
        //这里是将二维数组转换成了一层的直方图，一层一层的来遍历，
        vector<int> nums(matrix[0].size(),0);
        int maxarea = 0;
        for(auto i = 0;i < matrix.size();++i){
            for(int j = 0;j < matrix[i].size();++j){
                nums[j] = matrix[i][j] == '1' ? nums[j]+1:0;//底部为0则为0，为1则➕1
            }
            maxarea = max(maxarea,MaxRectangleArea(nums));
        }
        return maxarea;
    }
    //利用了求最大直方图的面积
   int MaxRectangleArea(vector<int> & height){
        stack<int> st;
        st.push(-1);
        int area = 0;
        for(int i = 0;i < height.size();++i){
            while(st.top() != -1 && height[st.top()] >= height[i]){
                int curtop = st.top();
                st.pop();
                area = max(area,height[curtop]*(i-1-st.top()));
            }
            st.push(i);
        }
        int l = height.size();
        while(st.top() != -1){
            int curtop = st.top();
            st.pop();
            area = max(area,height[curtop]*(l-1-st.top()));
        }
        return area;
    }
};
