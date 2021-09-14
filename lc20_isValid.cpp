#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

/**
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 有效字符串需满足：
 *      左括号必须用相同类型的右括号闭合。
 *      左括号必须以正确的顺序闭合。
 * 
 * 输入：s = "()"
 * 输出：true
 * 
 * 输入：s = "()[]{}"
 * 输出：true
 * 
 * 输入：s = "([)]"
 * 输出：false
 */

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        size_t size = s.size();
        if (size <= 1) return false;
        stack<char> char_stack;
        unordered_map<char,char> maps = {
            {')','('},
            {'}','{'},
            {']','['}
        };
        
        for (char c : s) {
            switch (c)
            {
            case '(':
            case '{':
            case '[':
            {
                char_stack.push(c);
            }
            break;
            case ')':
            case '}':
            case ']':
            {
                if (char_stack.size() > 0) {
                    char topc = char_stack.top();
                    if (topc == maps[c]) {
                        char_stack.pop();
                    } else {
                        char_stack.push(c);    
                    }
                } else {
                    char_stack.push(c);
                }
            }
            break;
            default:
            break;
            }
        }
        return (char_stack.size() == 0);
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    cout<<s.isValid(
        //"()"
        // "()[]{}"
        // "([)]"
        // "{[]}"
        // "}{"
        "(])"
    )<<endl;
    return 0;
}