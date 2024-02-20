#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m+n,0);
        int i = 0, j = 0, k = 0;
        for (; i < m && j < n; k++)
        {
            if (nums1[i] <= nums2[j]) {
                temp[k] = nums1[i];
                i++;
            } else {
                temp[k] = nums2[j];
                j++;
            }
        }
        if (i >= m) {
            for(;j < n;j++,k++) {
                temp[k] = nums2[j];
            }
        }
        if (j >= n) {
            for(;i < m;i++,k++) {
                temp[k] = nums1[i];
            }
        }
        nums1 = temp;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    s.merge(nums, m, nums2, n);
    for (auto i : nums) {
        cout<<i<<endl;
    }
    return 0;
}
