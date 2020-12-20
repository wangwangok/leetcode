#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 二分查找
     * @param n int整型 数组长度
     * @param v int整型 查找值
     * @param a int整型vector 有序数组
     * @return int整型
     */
    int upper_bound_(int n, int v, vector<int>& a) {
        if (n <= 0 || a.size() <= 0)
        {
            return 1;
        }
        if (n==1)
        {
            if (a[0] >= v)
            {
                return 1;
            }
            else
            {
                return 2;   
            }
        }
        int result = n+1;
        for (int left = 0, right = n-1, mid = (right - left) / 2;mid >= 0 && mid <= n-1 && right>=left; mid = left + (right - left) / 2)
        {
            if (a[mid] >= v)
            {
                result=mid+1;
                right=mid - 1;
            }
            else if (a[mid] < v)
            {
                left = mid + 1;
            }
        }
        return result;
    }
};


int main(int argc, const char *argv[]) {
    /// 5,4,[1,2,4,4,5]
    /// 10,2,[1,1,2,3,7,7,7,9,9,10]
    Solution s;
    vector<int> a{1,1,2,3,7,7,7,9,9,10};
    int result = s.upper_bound_(10,2,a);
    cout<<result<<endl;
    return 0;
}