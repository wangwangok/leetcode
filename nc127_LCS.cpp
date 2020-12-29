#include <iostream>
#include <string>

using namespace std;

/**
 * 给定两个字符串str1和str2,输出两个字符串的最长公共子串，如果最长公共子串为空，输出-1。
 * "1AB2345CD","12345EF"
 * "2345"
*/

class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        int col[m+1][n+1];
        int length = 0, cur_ptr = 0;
        for (int i = 0; i <= m; i++) col[i][0] = 0; /// 二维数组的第一列置为0
        for (int i = 0; i <= n; i++) col[0][i] = 0; /// 二维数组的第一行置为0
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1]) /// 下标从1开始
                {
                    col[i][j] = col[i - 1][j - 1] + 1; /// 获取当前已经重复的长度
                    cur_ptr = j;
                }
                else
                {
                    col[i][j] = 0; /// 这里由于是寻找子串，必须要连续。如果内容不同，则需要从头开始。而不是和最长子序列那样，可以不连续，而可以继续计数    
                }
                length = col[i][j] > length ? col[i][j] : length;
            }
        }
        if (length <= 0) return "";
        return str2.substr(cur_ptr - length, length);
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    string result = s.LCS("1AB2345EFCD","111111111");
    cout<<result<<endl;
    return 0;
}