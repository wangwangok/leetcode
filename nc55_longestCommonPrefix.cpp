#include <iostream>
#include <vector>
#include <string>
#include <iterator>

/**
 * 给你一个长度为 n 的字符串数组 strs , 编写一个函数来查找字符串数组中的最长公共前缀，返回这个公共前缀。
 * 输入：["abca","abc","abca","abc","abcc"]
 * 输出："abc"
 */


using namespace std;

class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() <= 0) return "";
        string prefix = strs[0];
        for (vector<string>::iterator itr = strs.begin(); itr != strs.end(); ++itr) {
            string temp = "";
            int min_len = prefix.length() < itr->length() ? prefix.length() : itr->length();
            for (int i = 0; i < min_len; i++) {
                if (prefix[i] == (*itr)[i]) {
                    temp.push_back(prefix[i]);
                } else {
                    break;
                }
            }
            prefix = temp;
        }
        return prefix;
    }
};

int main(int argc, const char* argv[]) {

    Solution s;
    vector<string> strs = {"abca", "abc", "abca", "abc", "abcc"};
    string result = s.longestCommonPrefix(strs);
    cout<<result<<endl;
    return 0;
}