#include <iostream>
#include <vector>

/**
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 */

using namespace  std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t size = nums.size();
        if (size <= 0) return 0;
        if (size == 1) return nums[0];

        int lead = 1, cur = 0;
        int max = nums[cur];
        int sum = max;
        while (lead < size) {
            sum += nums[lead];
            if (sum <= nums[lead]) {
                cur = lead;
                sum = nums[lead];
            }
            max = max > sum ? max : sum;
            lead++;
        }
        return max;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> list = {-2,1,-3,4,-1,2,1,-5,4,3};
    cout<<s.maxSubArray(list)<<endl;
    return 0;
}