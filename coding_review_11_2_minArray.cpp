#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int minArrayForLoop(vector<int>& nums) const {
        size_t size = nums.size();
        if (size <= 0)
        {
            return 0;
        }
        
        int ans = nums[0];
        for(vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr) {
            if (ans > *itr)
            {
                ans = *itr;
            }
        }
        return ans;
    }
public:
    int minArray(vector<int>& nums) const {
        size_t size = nums.size();
        if (size <= 0)
        {
            return 0;
        }
        int start = 0;
        int end = size - 1;
        
        int mid = 0;
        while(nums[start] >= nums[end]) { /// 由于数组是有序序列的一个旋转，因此最后一个元素肯定是小于第一个元素的
            if (end - start == 1)
            {
                mid = end;
                break;
            }
            mid = (end - start) / 2 + start;
            if (nums[start] == nums[end] && nums[mid] == nums[start])
            {
                return minArrayForLoop(nums);
            }
            
            if (nums[start] <= nums[mid])
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        return nums[mid];
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    vector<int> nums{2,1,3,5};
    int ans = s.minArray(nums);
    cout<<ans<<endl;
    return 0;
}