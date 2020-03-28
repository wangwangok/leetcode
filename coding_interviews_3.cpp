#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
    public:
    /// 根据题目定义，长度为n的的数组包含的数字在0~n-1的范围内
    vector<int> findRepeatNumbers(vector<int>& nums) {
        size_t size = nums.size();
        vector<int> result;
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr)
        {
            int index = itr - nums.begin();
            while (*itr != index)
            {
                if (*itr == nums[*itr])
                {
                    result.push_back(*itr);
                    break;
                }
                int temp = nums[*itr];
                nums[*itr] = *itr;
                *itr = temp;
            }
        }
        return result;
    }

    /* hash
    vector<int> findRepeatNumbers(const vector<int>& nums) {
        size_t size = nums.size();
        unordered_map <int,int> hash;
        vector<int> result;
        for (vector<int>::const_iterator itr = nums.begin(); itr != nums.end(); ++itr)
        {
            int index = itr - nums.begin();
            int value = hash[*itr];
            if (value > 0)
            {
                result.push_back(*itr);
            }
            hash[*itr] = ++value;
        }
        return result;
    }
    */
};


int main(int argc, const char* argv[]) {
    Solution s;
    vector<int> nums{2,3,1,0,2,5,3};
    vector<int> result = s.findRepeatNumbers(nums);
    for (vector<int>::iterator itr = result.begin(); itr != result.end(); ++itr)
    {
        cout<<*itr<<endl;
    }
    
    return 0;
}