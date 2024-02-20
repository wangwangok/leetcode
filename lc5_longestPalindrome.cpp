#include <iostream>
#include <string>

/**
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 输入：s = "a"
 * 输出："a"
 */

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const size_t size = s.size();
        if (size <= 1) return s;
        if (size == 2) return s[0]==s[1] ? s : to_string(s[0]);

        int max_len = 1;
        int p = 0;

        bool dp[size][size];
        for (int i = 0; i < size; i++) {
            dp[i][i] = true;
        }

        for (int len = 2; len < size; len++) {
            for (int lhs = 0; lhs < size; lhs++) {
                int rhs = len + lhs - 1;
                if (s[lhs] != s[rhs]) {
                    dp[lhs][rhs] = false;
                } else {
                    if (len <= 3) 
                    {
                        dp[lhs][rhs] = true;
                    }
                    else 
                    {
                        dp[lhs][rhs] = dp[lhs+1][rhs-1];
                    }
                }
                if (dp[lhs][rhs] && rhs >= lhs) {
                    max_len = max_len < len ? len : max_len;
                    p = lhs;
                }
            }
        }
        return s.substr(p, max_len);
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    cout<<s.longestPalindrome(
        "babad"
    )<<endl;
    return 0;
}