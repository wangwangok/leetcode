/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        int size = strs.size();
        if (size < 1) {
            return "";
        }

        if (size < 2) {
            return strs[0];
        }
        string result;
        string tmp = strs[0];
        int index = 1;
        while (index < size) {
            result.clear();
            string compare = strs[index];
            int step_length =
                tmp.size() < compare.size() ? tmp.size() : compare.size();
            for (int i = 0; i < step_length; i++) {
                if (tmp[i] != compare[i]) {
                    break;
                }
                result.push_back(tmp[i]);
            }
            tmp = result;
            index++;
        }
        result = tmp;
        return result;
    }
};
// @lc code=end
int main(int argc, const char *argv[]) {
    Solution s;
    vector<string> strs;
    string result = s.longestCommonPrefix(strs);
    cout << result << endl;
    return 0;
}
