//既然是有序数组的查找，最快就是二分查找了。
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        auto re = equal_range(data.begin(),data.end(),k);
        return re.second - re.first;
    }
};
