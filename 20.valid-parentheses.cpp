/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        size_t size = s.size();
        if (size <= 0)
        {
            return true;
        }
        if (size % 2 != 0)
        {
            return false;
        }
        int count = 4;
        map<char, char>pairs = {
            make_pair('(',')'),
            make_pair('[',']'),
            make_pair('{','}')
        };
        bool ans = false;
        int index = 0;
        vector<char> stack;
        while (index < size)
        {
            bool containKey = false;
            for (map<char, char>::iterator itr = pairs.begin(); itr != pairs.end(); ++itr)
            {
                if (s[index] == itr->first)
                {
                    containKey = true;
                    break;
                }
            }
            if (containKey)
            {
                /// 入栈
                stack.push_back(s[index]);
                ans = true;
            }
            else
            {
                if (stack.size() <= 0)
                {
                    ans = false;
                    return ans;
                }
                
                char chr = stack.back();
                if (pairs[chr] == s[index]) {
                    stack.pop_back();
                }
            }
            index++;
        }
        if (stack.size() > 0)
        {
            ans = false;
        }
        
        return ans;
    }
};
// @lc code=end

int main(int argc, const char *argv[]) {
    Solution s;
    cout<<s.isValid("){")<<endl;
    return 0;
}