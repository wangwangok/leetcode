#include <vector>
#include <iostream>

using namespace std;
class Solution {
private:
    int count(const vector<int>& nums, int start, int end) {
        int count = 0;
        for (vector<int>::const_iterator itr = nums.begin(); itr != nums.end(); ++itr)
        {
            if (*itr <= end && *itr >= start)
            {
                count++;
            }
        }
        return count;
    }
public:
    int findDuplicateNum(const vector<int>& nums) {
        size_t size = nums.size();
        if (size <= 0)
        {
            return -1;
        }
        int start = 1;
        int end = size - 1;
        while(start <= end) {
            int mid = ((end - start) >> 1) + start;
            int cnt = count(nums, start, mid);
            if (end == start) {
                if (cnt > 1)
                {
                    return start;
                }
                return -1;
            }
            
            if(cnt > mid - start + 1) 
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
};

int main(int argc, const char* argvp[]) {
    vector<int> nums{2,3,5,4,3,2,6,7};
    Solution s;
    int ans = s.findDuplicateNum(nums);
    cout<<ans<<endl;
    return 0;
}