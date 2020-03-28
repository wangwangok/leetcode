#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRepeatNumbersNoEdit(const vector<int>& nums) {
        size_t size = nums.size();
        if (size <= 0)
        {
            return {};
        }
        vector<int> field(size,0);
        vector<int> result;
        for (vector<int>::const_iterator itr = nums.begin(); itr != nums.end(); ++itr)
        {
            int value = field[*itr];
            if (value != 0)
            {
                result.push_back(*itr);
            }
            else
            {
                field[*itr] = 1;
            }
        }
        return result;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    vector<int> nums{2,3,5,4,3,2,6,7};
    vector<int> result = s.findRepeatNumbersNoEdit(nums);
    for (vector<int>::iterator itr = result.begin(); itr != result.end(); ++itr)
    {
        cout<<*itr<<endl;
    }
    return 0;
}