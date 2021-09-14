#include <iostream>
#include <string>

/**
 * 
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
 * 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 输入：num1 = "11", num2 = "123"
 * 输出："134"
 * 
 * 输入：num1 = "456", num2 = "77"
 * 输出："533"
 */

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        size_t size1 = num1.size();
        size_t size2 = num2.size();
        if (size1 == 0) return num2;
        if (size2 == 0) return num1;
        int curry = 0;
        string str = "";
        for (int i = size1 - 1, j = size2 - 1; i >= 0 || j >= 0;) 
        {
            int lhs = 0;
            if (i >= 0) {
                lhs = num1[i--] - '0';
            }
            int rhs = 0;
            if (j >= 0) {
                rhs = num2[j--] - '0';
            }
            int sum = lhs + rhs + curry;
            curry = sum / 10;
            char v = sum % 10 + '0';
            str = v + str;
        }
        if (curry > 0) {
            char v = curry + '0';
            str = v + str;
        }
        return str;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    cout<<s.addStrings(
        // "11","123"
        // "456","77"
        "1","9"
    )<<endl;
    return 0;
}