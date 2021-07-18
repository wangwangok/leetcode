#include <iostream>
#include <vector>

/*
描述

请实现有重复数字的升序数组的二分查找
给定一个 元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的第一个出现的target，
如果目标值存在返回下标，否则返回 -1

## 示例1
输入：[1,2,4,4,5],4
返回值：2
说明：从左到右，查找到第1个为4的，下标为2，返回2

## 示例2
输入：[1,2,4,4,5],3
返回值：-1

## 示例3
输入：[1,1,1,1,1],1
返回值：0
*/

using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 如果目标值存在返回下标，否则返回 -1
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int result = -1;
        if (right == 0)
        {
            return result;
        }
        
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                result = mid;
                right = mid - 1;
            }
        }
        return result;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    vector<int> inputs = {1,2,2,4};
    cout<<s.search(inputs, 2)<<endl;
    return 0;
}