#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int __partition(vector<int>& nums, int start, int end) {
        size_t size = nums.size();
        if (start < 0 || end < 0 || start >= size || end >= size || start == end)
        {
            return -1;
        }
        size = end - start;
        int random = rand() % size + start;
        __swap(nums,random,end);
        int pivot = nums[end];
        int i = start - 1;
        for (int j = start; j < end; j++)
        {
            if (nums[j] > pivot)
            {
                continue;
            }
            i = i + 1;
            __swap(nums, i, j);
        }
         __swap(nums, i+1, end);
         return i+1;
    }

    void __swap(vector<int>& nums, int lhs, int rhs) {
        size_t size = nums.size();
        if (lhs < 0 || rhs < 0 || lhs >= size || rhs >= size || lhs == rhs)
        {
            return;
        }
        nums[lhs] = nums[lhs]^nums[rhs];
        nums[rhs] = nums[rhs]^nums[lhs];
        nums[lhs] = nums[lhs]^nums[rhs];
    }

public:

    void quick_sort(vector<int>& nums, int start, int end) {
        if (start >= end)
        {
            return;
        }
        
        size_t size = nums.size();
        if (size <= 0)
        {
            return;
        }
        int divide = __partition(nums, start, end);
        if (divide > start)
        {
            quick_sort(nums, start, divide - 1);
        }
        if (divide < end)
        {
            quick_sort(nums, divide + 1, end);   
        }
    }
};

int main(int argc, const char *argv[]) {
    vector<int> nums{3,4,1,5,7,9,2,11};
    Solution s;
    size_t size = nums.size();
    s.quick_sort(nums, 0, size - 1);
    for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr) {
        cout<<*itr<<endl;
    }
    return 0;
}