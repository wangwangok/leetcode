#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        if (s.size() <= 0 || s.size() % 2 != 0)
        {
            return false;
        }
        stack<int> stack;
        for (auto c : s)
        {
            switch (c)
            {
            case '(':
            {
                stack.push(1);
            }
                break;
            case ')':
            {
                if (stack.empty())
                {
                    return false;
                }
                int top = stack.top();
                if (top != 1)
                {
                    return false;
                }
                stack.pop();
            }
                break;
            case '{':
            {
               stack.push(2); 
            }
                break;
            case '}':
            {
                if (stack.empty())
                {
                    return false;
                }
                int top = stack.top();
                if (top != 2)
                {
                    return false;
                }
                stack.pop();
            }
                break;
            case '[':
            {
                stack.push(3);
            }
                break;
            case ']':
            {
                if (stack.empty())
                {
                    return false;
                }
                int top = stack.top();
                if (top != 3)
                {
                    return false;
                }
                stack.pop();
            }
                break;
            default:
                break;
            }
        }
        return stack.empty();
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    cout<<s.isValid("([)]")<<endl;
    return 0;
}