#include <iostream>
#include <vector>

/**
 * 
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
 * 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 0
 * 输出：4
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 3
 * 输出：-1
 * 
 * 输入：nums = [1], target = 0
 * 输出：-1
 */

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t size = nums.size();
        if (size <= 0) return -1;
        int left = 0, right = size - 1;
        int r = -1;
        while (left < right)
        {
            int mid = left + (right - left + 1)/2;
            if (mid == right) {
                r = mid;
                break;
            }
            if (mid > left && mid < right && nums[mid] < nums[mid-1] && nums[mid] < nums[mid + 1]) {
                /// 旋转点
                r = mid;
                break;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            }
            if (nums[mid] > nums[left]) {
                left = mid;
            }
        }
        if (r < 0 && r >= size) {
            return binarySearch(nums,0, size - 1, target);
        }
        if (target == nums[r]) return r;
        if (target >= nums[0]) {
            left = 0, right = r-1;
        } else if (target <= nums[size - 1]) {
            left = r, right = size - 1;
        }
        return binarySearch(nums,left, right, target);
    }

    int binarySearch(vector<int>&list, int left, int right, int target) {
        while (left <= right)
        {
            int mid = left + (right - left + 1)/2;
            if (target == list[mid]) return mid;
            if (target < list[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return - 1;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    vector<int> v = {3,1};
    int target = 1;
    cout<<s.search(v, target)<<endl;
}