#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
    void quickSort(vector<int> &nums) {
        size_t n_size = nums.size();
        if (n_size < 1) {
            return;
        }
    }

    void partition(vector<int> &nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int i = left + 1, j = right, pi = left;
        while (i < j) {
            if (nums[i] <= nums[pi] && i <= right) {
                i++;
            }
            if (nums[j] > nums[pi] && j > left) {
                j--;
            }
            if (i < j) {
                swap(nums, i, j);
            }
        }
        if (nums[pi] > nums[j]) {
            swap(nums, pi, j);
        }
        partition(nums, left, j - 1);
        partition(nums, j + 1, right);
    }

    void swap(vector<int> &nums, int lhs, int rhs) {
        nums[lhs] = nums[lhs] ^ nums[rhs];
        nums[rhs] = nums[rhs] ^ nums[lhs];
        nums[lhs] = nums[lhs] ^ nums[rhs];
    }

  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        size_t n_size = nums.size();
        vector<int> result = {};
        if (n_size <= 1)
            return result;
        map<int, int> tMap;
        for (size_t i = 0; i < n_size; i++) {
            int v = target - nums[i];
            if (tMap.find(v) != tMap.end()) {
                result.push_back(tMap[v]);
                result.push_back(i);
                break;
            } else {
                tMap[nums[i]] = i;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> nums = {7, 4, 5, 3, 11, 15};
    //{3, 2, 4};
    int target = 18;
    // 6;
    vector<int> result = s.twoSum(nums, target);
    for (auto item : result) {
        cout << item << endl;
    }
    return 0;
}
