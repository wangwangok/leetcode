/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <iostream>
#include <string>
using namespace std;

// @lc code=start

class Solution {
public:
    struct Window{
        uint start;
        uint end;
        Window() {
            start = 0;
            end = 1;
        }
    };

    int lengthOfLongestSubstring(string s) {
       int max_length = 0;
       Window window;
       size_t size = s.size();
       if (size <= 1)
       {
           return size;
       }
       
       while (window.end < size && window.start <= window.end)
       {
            char chr = s[window.end];
            if (window.end <= window.start)
            {
                return 0;
            }
            
            string substr = s.substr(window.start,window.end-window.start);
            /// hash
            for (string::iterator i = substr.begin(); i != substr.end(); i++)
            {
                if (*i != chr)
                {
                    continue;
                }
                int index = i-substr.begin();
                window.start += index+1;
                break;
            }
            window.end++;
            uint length = window.end-window.start;
            max_length = max_length <= length ? length : max_length; 
       }
       return max_length; 
    }
};
// @lc code=end
int main(int argc, const char *argv[]) {
    Solution s;
    int result = s.lengthOfLongestSubstring(" ");
    cout<<result<<endl;
    return 0;
}
