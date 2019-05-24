//归并排序的思想，将数组分成两份，每份再继续分，然后再合并。
//参考文章：https://yq.aliyun.com/articles/642775
//逆序对：左边数大右边数。
class Solution {
public:
    int count =0;
    int InversePairs(vector<int> data) {
        if(data.size() <= 1)
        {
            return count;
        }
        MergeSort(data,0,data.size()-1);
        return count;
    }
    void MergeSort(vector<int> & data,int left,int right)
    {
        if(left < right)
        {
            int mid = right/2 + left/2;
            
            MergeSort(data,left,mid);
            MergeSort(data,mid+1,right);
            
            Merge(data,left,right,mid);
        }
    }
    void Merge(vector<int> &data,int left,int right,int mid){
        vector<int> tmp;
        int m = mid;
        int r = right;
        while(right > m && mid >= left)
        {
            if(data[right] >= data[mid])
            {
                tmp.push_back(data[right--]);
            }
            if(data[mid] > data[right]){
                count += right - m;
                if(count >= 1000000007)
                {
                    count %= 1000000007;
                }
                tmp.push_back(data[mid--]);
            }
        }
        while(right > m)
        {
            tmp.push_back(data[right--]);
        }
        while(mid >= left)
        {
            tmp.push_back(data[mid--]);
        }
        for(int i = 0;i < tmp.size();++i)
        {
            data[r-i] = tmp[i];
        }
    }
};
