#include <iostream>
#include <string>

/**
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 输入:s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
    
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        size_t size = s.size();
        if (size < 2) return size;
        int left = 0, right = 1;
        for (;right < size;) {
            if (left > right) break;
            string::iterator bchr_itr = s.begin() + right;
            string substr = s.substr(left, right - left);
            for (string::iterator sitr = substr.begin(); sitr != substr.end(); ++sitr) {
                if (*bchr_itr != *sitr) continue;
                int idx = sitr - substr.begin();
                left += (idx + 1); /// 将指针移动到重复字符的下一个位置
            }
            right++;
            maxlen = max(maxlen, right - left);
        }
        return maxlen;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    int maxlen = s.lengthOfLongestSubstring(
        //"abcabcbb"
        //"bbbbb"
        //"pwwkew"
        //"abcdce"
        "a"
        );
    cout<<maxlen<<endl;
    return 0;
}