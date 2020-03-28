/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
/**
    struct palindromeNode {
        char value;
        /// 构成回文串的期望字符，由于本身value可以构成回文。因此这里不包含本身
        char expect; 
        int index;
        palindromeNode *next;
        palindromeNode(char val, char exp, int idx):value(val),expect(exp),index(idx){}
        palindromeNode(char val, int idx):value(val){
            index = idx;
            expect = 0;
        }
    };  

    string longestPalindrome(string s) {
        size_t size = s.size();
        if (size <= 0)
        {
            return "";
        }
        palindromeNode *top = nullptr;
        string palindromicStr;
        string temp_palin_str;
        int symmetric_startptr = 0;
        int symmetric_endptr = symmetric_startptr;
        for (string::iterator i = s.begin(); i != s.end(); i++)
        {
            temp_palin_str = *i;
            int index = i - s.begin();
            palindromeNode *node = new palindromeNode(*i, index);
            if (node == nullptr)
            {
                break;
            }
            if (top == nullptr)
            { /// 栈为空
                top = node; 
                palindromicStr = *i;
                temp_palin_str = top->value;
                continue;
            }
            int top_index = top->index; 
            if (*i == top->value || *i == top->expect)
            {
                temp_palin_str.push_back(*i);
                size_t temp_size = temp_palin_str.size();
                //symmetric_startptr = index - temp_size/2;
                symmetric_endptr = index - temp_size + 1;
                symmetric_startptr = (index - symmetric_endptr) / 2 + symmetric_endptr;
                int offset = symmetric_endptr - 1;
                if (offset < 0)
                {
                    node->expect = top->value;
                    symmetric_startptr = 0;
                    symmetric_endptr = symmetric_startptr;
                }
                else
                {
                    node->expect = s[symmetric_endptr - 1];
                }
                palindromicStr = palindromicStr.size() < temp_palin_str.size() ? temp_palin_str : palindromicStr;
            }
            else
            {
                temp_palin_str = top->value;
                node->expect = top->value;
                symmetric_startptr = 0;
                symmetric_endptr = symmetric_startptr;
            }
            top->next = node;
            top = node;
        }
        return palindromicStr;
    }
*/

    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        size_t size = s.size();
        string result;
        for(int i = 0; i < size; ++i)
        {
            int len1 = lengthPalindrome(i,i,s);
            int len2 = lengthPalindrome(i,i+1,s);
            int len = len1>=len2?len1:len2;
            if (len > end-start+1)
            {
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int lengthPalindrome(int start, int end, string s)
    {
        if (start > end)
        {
            return 0;
        }
        size_t size = s.size();
        while(start >= 0 && end <= size-1)
        {
            if (s[start] == s[end])
            {
                start--;
                end++;
            }
            else
            {
                break;
            }
            
        }
        return end-start-1;
    }
};
// @lc code=end

