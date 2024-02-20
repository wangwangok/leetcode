#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t size = nums.size();
        if (size <= 1) return size;
        int lhs = 0;
        int v_count = 0;
        for (int i = 1; i < size; i++) {
            if (nums[lhs] != nums[i]) {
                if (i - lhs > 1) {
                    nums[lhs + 1] = nums[i];
                    lhs++;
                } else {
                    lhs = i;
                }
            } else {
                v_count++;
            }
        }
        return size - v_count;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4,5,5};
    size_t size = s.removeDuplicates(nums);
    for (int i = 0; i < size; i++) {
        cout<<nums[i]<<endl;
    }
    return 0;
}
