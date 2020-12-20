/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> value;
         sort(nums.begin(), nums.end());
         size_t size = nums.size();
         if (size < 4)
         {
             return value;
         }
         
         for (size_t i = 0; i < size - 3; i++) {
             if (i > 0 && nums[i] == nums[i-1])
             { /// 先保证越过相邻两个相同元素
                 continue;
             }
             for (size_t j = i+1; j < size - 2; j++)
             {
                 if (j > i+1 && nums[j] == nums[j-1])
                 { /// 先保证越过相邻两个相同元素
                     continue;
                 }
                 for (size_t m = j+1, n = size - 1; m < n;)
                 {
                    int result = nums[i] + nums[j] + nums[m] + nums[n];
                    if (result < target)
                    {
                        m++;    
                    }
                    else if (result > target)
                    {
                        n--;
                    }
                    else
                    {
                        vector<int> current{nums[i], nums[j], nums[m], nums[n]};
                        value.push_back(current);
                        while (m < n && nums[m]==nums[m+1])
                        { /// 先保证越过相邻两个相同元素
                            m++;
                        }
                        while (m < n && nums[n]==nums[n-1])
                        { /// 先保证越过相邻两个相同元素
                            n--;
                        }
                        m++;
                        n--;
                    }
                 }
             }
         }
        return value;
    }
};
// @lc code=end

int main(int argc, const char* argv[]) {
    Solution s;
    vector<int> input{4,-9,-2,-2,-7,9,9,5,10,-10,4,5,2,-4,-2,4,-9,5};
    int target = -13;
    vector<vector<int>> value = s.fourSum(input, target);
    for (vector<vector<int>>::iterator i = value.begin(); i != value.end(); i++)
    {
       cout<<"[";
       for (vector<int>::iterator j = i->begin(); j != i->end(); j++)
       {
           cout<<*j<<", ";
       }
       cout<<"], "<<endl;
    }
    
    return 0;
}