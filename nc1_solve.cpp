#include <iostream>
#include <string>
#include <iterator>

using namespace std;

/**
 * 以字符串的形式读入两个数字，编写一个函数计算它们的和，以字符串形式返回。
 *（字符串长度不大于100000，保证字符串仅由'0'~'9'这10种字符组成）
 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        if (t.size() <= 0) return s;
        if (s.size() <= 0) return t;
        string::iterator s_itr = s.end() - 1, t_itr = t.end() - 1;
        string result;
        unsigned carryin = 0;
        for (bool s_noend = s_itr != s.begin() - 1 ,t_noend = t_itr != t.begin() - 1;
            s_noend || t_noend || carryin > 0; 
            s_noend = s_itr != s.begin() - 1, t_noend = t_itr != t.begin() - 1)
        {
            unsigned sum = (s_noend ? (*s_itr - '0') : 0) + (t_noend ? (*t_itr - '0') : 0) + carryin;
            unsigned val = sum % 10;
            carryin = sum / 10;
            result.push_back(val + '0');
            if (s_noend) s_itr--;
            if (t_noend) t_itr--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    string result = s.solve("4524523452354326543653563654365","43153154");
    cout<< result << endl;
    return 0;
}