#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int current_step = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > current_step) {
                return false;
            }
            current_step = max(current_step, nums[i] + i);
        }
        return true;
    }
};


int main(int argc, const char *argv) {
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    bool result = s.canJump(nums);
    cout<<result<<endl;
    return 0;
}