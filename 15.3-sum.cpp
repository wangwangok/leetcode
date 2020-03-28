/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include <vector>
#include <iostream>
#include <cstdlib>


using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t size = nums.size();
        if (size <= 0)
        {
            return {};
        }
        quick_sort(nums,0,size-1);
        vector<vector<int> > results;
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr)
        {
            if (*itr > 0)
            {
                break;
            }
            if (itr - nums.begin() > 0 && *itr == *(itr-1))
            {
                continue;
            }
            vector<int>::iterator left_ptr = itr + 1;
            vector<int>::iterator right_ptr = nums.end() - 1;
            int des = (*itr) * -1;
            while (right_ptr - left_ptr > 0)
            {
                if (*right_ptr + *left_ptr < des)
                {
                    ++left_ptr;
                }
                else if (*right_ptr + *left_ptr == des)
                {   
                    vector<int>tmp{*itr,*left_ptr,*right_ptr};
                    results.push_back(tmp);
                    while (right_ptr - left_ptr > 0 && *right_ptr == *(right_ptr - 1))
                    {
                        --right_ptr;
                    }
                    while (right_ptr - left_ptr > 0 && *left_ptr == *(left_ptr + 1))
                    {
                        ++left_ptr;
                    }
                    --right_ptr;
                    ++left_ptr;
                }
                else
                {
                    --right_ptr;
                }
            }
        }
        return results;
    }

    void quick_sort(vector<int>& nums, int left, int right) {
        if (left > right)
        {
            return;
        }
        int divide = partition(nums,left,right);
        quick_sort(nums,left, divide - 1);
        quick_sort(nums,divide + 1, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        size_t size = right + 1 - left;
        srand(int(time(0)));
        int index = left + random() % size;
        swap(nums, right, index);
        int i = left - 1;
        for (int j = left; j < right; j++)
        {
            if (nums[j] >= nums[right])
            {
                continue;
            }
            i = i + 1;
            swap(nums, i, j);
        }
        swap(nums, i+1, right);
        return i+1;
    }

    void swap(vector<int>& nums, int lhs, int rhs) {
        if (lhs == rhs)
        {
            return;
        }
        nums[lhs]=nums[lhs]^nums[rhs];
        nums[rhs]=nums[rhs]^nums[lhs];
        nums[lhs]=nums[lhs]^nums[rhs];
    }
};
// @lc code=end

int main(int argc, const char *argv[]) {
    Solution s;
    /// -2,0,0,2,2
    /// -1, 0, 1, 2, -1, -4
    vector<int> nums{-2,0,0,2,2};
    vector<vector<int> >result = s.threeSum(nums);
    for (vector<vector<int>>::iterator itr = result.begin(); itr != result.end(); ++itr)
    {
        cout<<"------------------"<<endl;
        for (vector<int>::iterator inner = itr->begin(); inner != itr->end(); ++inner)
        {
            cout<<*inner<<endl;
        }
        
    }
    return 0;
}