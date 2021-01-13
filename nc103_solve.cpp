#include <iostream>
#include <string>
#include <iterator>

using namespace std;

/*
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）
*/

class Solution {
public:
    /**
     * 反转字符串
     * @param str string字符串 
     * @return string字符串
     */
    string solve(string str) {
        if (str.size() <= 1) return str;
        for (string::iterator left = str.begin(), right = str.end() - 1; left - str.begin() <= right - str.begin(); left++, right--)
        {
            *left  ^= *right;
            *right ^= *left;
            *left  ^= *right;
        }
        return str;
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    string result = s.solve("\x00zdsbdzhtmsetfwlvoheadlenazgzhcdllfxhfxufkenhuvzcyticztyfiatcuptkjffcppvvvjrcaiurzqmuupfriaektbntfpstlzssrqzicivmtpfabekrrpgstwweys");
    cout<<result<<endl;
    return 0;
}