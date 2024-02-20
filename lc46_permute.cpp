#include <iostream>
#include <vector>

/**
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 * 
 * 输入：nums = [0,1,2,3]
 *  4 * 3 * 2 * 1
 */

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector<int> >result;
        rvpermute(result, nums, 0);
        return result;
    }
private:

    void sswap(vector<int>& nums, int lhs, int rhs) {
        if (lhs == rhs || (lhs < 0 || lhs >= nums.size()) || (rhs < 0 || rhs >= nums.size())) return;
        nums[lhs] ^= nums[rhs];
        nums[rhs] ^= nums[lhs];
        nums[lhs] ^= nums[rhs];
    }

    void rvpermute(vector<vector<int>>& rs, vector<int> rnums, int cIdx) {
        if (cIdx == rnums.size() - 1) {
            rs.push_back(rnums);
        }
        for (int i = cIdx; i < rnums.size(); ++i) {
            sswap(rnums, cIdx, i);
            rvpermute(rs, rnums, cIdx + 1);
            sswap(rnums, i, cIdx);
        }
    }
};

int main(int argc, const char* argv[]) {

    Solution s;
    vector<int> nums;
    vector<vector<int>> result = s.permute(nums);
    for (vector<int> iarray : result) {
        cout<<endl;
        cout<<"[";
        for (int item : iarray) {
            cout<<item<<",  ";
        }
        cout<<"]";
    }
    return 0;
}