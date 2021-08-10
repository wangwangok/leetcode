#include <iostream>
#include <string>
#include <stack>
#include<cstring>

/*
描述
请写一个整数计算器，支持加减乘三种运算和括号。

## 示例1
输入："1+2"
返回值：3

## 示例2
输入："(2*(3-4*6))*5"
返回值：-10

## 示例3
输入："3+2*3*4-1"
返回值：26
*/

using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    int solve(string s) {
        int result = 0;
        if (s.size() <= 0)
        {
            return result;
        }
        stack<int> num_stack;
        int number = 0;
        char op = '+';
        for (string::iterator itr = s.begin(); itr != s.end(); ++itr)
        {
            char c = *itr;
            if (c == ' ') {
                continue;
            }
            if (c >= 48 && c <= 57)
            {
                int n = c - 48;
                number = number * 10 + n;
            }
            if (c == '(')
            {
                int op_num = 1;
                string::iterator op_itr = itr + 1;
                for (; op_itr != s.end() && op_num > 0; ++op_itr)
                {
                    if (*op_itr == ')')
                    {
                        op_num--;
                    }
                    /// 说明当前字符串还包含括号表达式
                    if (*op_itr == '(')
                    {
                        op_num++;
                    }
                }
                if (op_num == 0)
                {
                    number = solve(s.substr(itr-s.begin() + 1, (op_itr - 1) - itr - 1));
                }
                itr = op_itr - 1;
            }
            c = *itr;
            if (c == '+' ||
                c == '-' ||
                c == '*' || 
                itr == s.end() - 1) 
            {
                if (op == '+') {
                    num_stack.push(1 * number);
                    number = 0;
                } else if (op == '-') {
                    num_stack.push(-1 * number);
                    number = 0;
                } else if (op == '*') {
                    number = number * num_stack.top();
                    num_stack.pop();
                    num_stack.push(number);
                    number = 0;
                }
                op = c;
            }
        }
        
        while (num_stack.size() > 0)
        {
            result += num_stack.top();
            num_stack.pop();
        }
        return result;
    }
};


int main(int argc, const char* argvp[]) {
    Solution s;
    // (2*(36-4*6+7*8+9))*5-1
    int result = s.solve("3+2*3*4-1"); 
    cout<<result<<endl;
    return 0;
}
