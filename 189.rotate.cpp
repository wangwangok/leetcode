#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate1(vector<int>& nums, int k) {
        size_t size = nums.size();
        k = k % size;
        if (k >= size || k <= 0) {
            return;
        }
        vector<int> c_nums;
        for (int i = size - k; i < size; i++) {
            c_nums.push_back(nums[i]);
        }
        for (int i = 0; i <= size - 1 - k; i++) {
            c_nums.push_back(nums[i]);
        }
        nums = c_nums;
    }

    void rotate(vector<int>& nums, int k) {
        size_t size = nums.size();
        k = k % size;
        if (k >= size || k <= 0) {
            return;
        }
        int lhs = 0;
        int rhs = size - k;
        while(k < size && k > 0) {
            for (int i = 0; i < k && lhs + i < rhs; i++) {
                int temp = nums[lhs + i];
                nums[lhs + i] = nums[rhs + i];
                nums[rhs + i] = temp;
            }
            if (lhs + k >= rhs) {
                size = size - rhs;
                k = k % size;
            }
            lhs = rhs;
            rhs = size - k;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {1,2,3,4};
    int k = 3;
    s.rotate(nums, k);
    for (auto item : nums) {
        cout<<item<<endl;
    }
    return 0;
}
