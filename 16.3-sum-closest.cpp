/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        size_t size = nums.size();
        if (size <= 0) {
            return 0;
        }
        quick_sort(nums, 0, size - 1);
        int min_gap = INT_MAX;
        int result = INT_MAX;
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
        {
            int index = i - nums.begin();
            int left = index + 1;
            int right = size - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right] + *i;
                if (sum == target)
                {
                    return sum;
                }
                if (min_gap > abs(target - sum))
                {
                    min_gap = abs(target - sum);
                    result = sum;
                }
                
                if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return result;
    }

    /// -1: not contain
    /// >= 0: target index
    int binary_search(vector<int>& nums, int target) {
        int index = -1;
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + ((end - start) >> 1);
            if (nums[mid] == target)
            {
                index = mid;
                break;
            }
            
            if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return index;
    }

    /// quick sort
    void quick_sort(vector<int>& nums, int left, int right) {
        if (left > right)
        {
            return;
        }
        int mid = partition(nums,left, right);
        quick_sort(nums,left, mid - 1);
        quick_sort(nums, mid+1, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        int size = right - left + 1;
        int index = left + (random() % size);
        lswap(nums, index, right);
        int start = left - 1;
        for (int lead = left; lead < right; lead++)
        {
            if (nums[lead] >= nums[right])
            {
                continue;
            }
            start++;
            lswap(nums, start, lead);
            
        }
        lswap(nums, start + 1, right);
        
        return start + 1;
    }

    void lswap(vector<int>& nums, int lhs, int rhs) {
        if (lhs == rhs)
        {
            return;
        }
        
        nums[lhs] = nums[lhs] ^ nums[rhs];
        nums[rhs] = nums[rhs] ^ nums[lhs];
        nums[lhs] = nums[lhs] ^ nums[rhs];
    }
};
// @lc code=end

int main(int argc, const char *argvp[]) {
    Solution s;
    /// -2,0,0,2,2
    /// 
    vector<int> nums{-1, 2, 1, -4};
    int result = s.threeSumClosest(nums, 1);
    cout<<result<<endl;
    return 0;
}
