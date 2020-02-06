//既然是两个有序的数组，那么肯定是归并，但是题目中说，A的空间足够大，所以要利用原来的空间。
//那么就想到了可以倒着归并。

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int be = n-1;
        int ae = m-1;
        int index = m+n-1;
        while(be >= 0 && ae >= 0){
            if(A[ae] > B[be])
                A[index] = A[ae--];
            else
                A[index] = B[be--];
            index--;
        }
        while(be >= 0){
            A[index--] = B[be--];
        }
    }
};

/*
给出两个有序的整数数组A和B，请将数组B合并到数组A中，变成一个有序的数组
注意：
可以假设A数组有足够的空间存放B数组的元素，A和B中初始的元素数目分别为m和n

*/
