#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        size_t size = nums.size();
        vector <int> ans;
        if (size <= 0)
        {
            return {};
        }
        for(int idx = 0; idx < size; ++idx) {
            if (idx == nums[idx])
            {
                continue;
            }
            int temp = nums[idx];
            if (nums[temp] == temp)
            {
                ans.push_back(temp);
                continue;
            }
            nums[idx] = idx;
            nums[temp] = temp;
        }
        return ans;
    }
};

int main(int argc, const char* argv[]) {
    vector<int> nums{2,3,1,0,2,5,3};
    Solution s;
    vector<int> ans = s.findDuplicates(nums);
    for (vector<int>::iterator itr = ans.begin(); itr != ans.end(); ++itr)
    {
        cout<<*itr<<endl;
    }
    return 0;
}