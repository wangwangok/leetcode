#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t len = nums.size();
        if (len < 1) return len;
        int v_count = 0;
        int lhs = -1, rhs = -1;
        if (len == 1) {
            if (nums[0] == val) {
                return 0;
            } else {
                return 1;
            }
        } 
        for (int i = 0; i < len; i++) {
            auto item = nums[i];
            if (item == val) {
                if (lhs == -1) {
                    lhs = i;
                }
                v_count++;
            } else if (lhs != -1) {
                nums[lhs] = nums[i];
                lhs++;
            }
        }
        return len - v_count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int len = s.removeElement(nums, val);
    for (int i = 0; i < len; i++) {
        cout<<nums[i]<<endl;
    }
    return 0;
}
