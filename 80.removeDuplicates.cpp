#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t size = nums.size();
        int dc = 2;
        int idx = 0;
        if (size < dc) return size;
        for (auto item : nums) {
            if (idx < dc) {
                idx++;
                continue;
            }
            if (item != nums[idx - dc]) {
                nums[idx] = item;
                idx++;
            }
        }
        return idx;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums{0,0,1,1,1,1,2,3,3};
    int len = s.removeDuplicates(nums);
    for (int i = 0; i < len; i++)
    {
        cout<<nums[i]<<endl;
    }
    return 0;
}
