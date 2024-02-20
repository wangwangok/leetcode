#include <iostream>
#include <string>

/**
 * 给出一个字符串 S，考虑其所有重复子串（S 的连续子串，出现两次或多次，可能会有重叠）。
 * 返回任何具有最长可能长度的重复子串。（如果 S 不含重复子串，那么答案为 ""。）
 * 
 * 输入："banana"
 * 输出："ana"
 * 
 * 输入："abcd"
 * 输出：""
 */

using namespace std;

class Solution {
public:
    string longestDupSubstring(string s) {
        const size_t n = s.size();
        if (n <= 0) return "";
        int nums[n];
        for (int i = 0; i < n; i++) {
            nums[i] = s[i] - 'a';
        }
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

        }
    }

    int search(string s, int base) {

    }
};

int main(int argc, const char* argv[]) {

    return 0;
}