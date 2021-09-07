#include <iostream>
#include <vector>

/**
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 */

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        size_t size = nums.size();
        sort(nums);
        if (k > size) return nums[size-1];
        return nums[size - k];
    }

private:

    void sort(vector<int> &nums) {
        partition(nums, 0, nums.size() - 1);
    }

    void partition(vector<int> &nums, int lhs, int rhs) {
        if (lhs < 0 || lhs > nums.size()) return;
        if (rhs < 0 || rhs > nums.size()) return;
        if (lhs > rhs) return;
        int pt = lhs;
        int left = lhs + 1;
        int right = rhs;
        while (left < right) {
            while (nums[left] <= nums[pt] && left <= rhs) left++;
            while (nums[right] > nums[pt] && right >= lhs) right--;
            if (left < right) swap(nums, left, right);
        }
        if (nums[pt] > nums[right]) swap(nums, pt, right);
        partition(nums, lhs, right - 1);
        partition(nums, right+1, rhs);
    }

    void swap(vector<int> &nums, int lhs, int rhs) {
        nums[lhs] ^= nums[rhs];
        nums[rhs] ^= nums[lhs];
        nums[lhs] ^= nums[rhs];
    } 
};

int main(int argc, const char* argv[]) {
    Solution s;
    vector<int> nums = {3,3,3,3,3,3,3,3,3}
    //{2,1}
    //{3,2,3,1,2,4,5,5,6}
    //{3,2,1,5,6,4}
    ;

    int k = 1
    // 2
    // 4
    // 2
    ;
    cout<<s.findKthLargest(nums, k)<<endl;
    return 0;
}