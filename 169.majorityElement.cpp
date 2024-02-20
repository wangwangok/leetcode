#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums[0];
        }
        int element = nums[0];
        int currentValue = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (currentValue == 0) {
                element = nums[i];
            }
            if (nums[i] == element) {
                currentValue++;
            } else {
                currentValue--;
            }
        }
        return element;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {2,2,1,1,3,1,3,3,3,1,3,1,2,4,4,4,0,2,4,2};
    int elem = s.majorityElement(nums);
    cout<<elem<<endl;
    return 0;
}
