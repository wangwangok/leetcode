/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int size = s.size();
        if (size <= 0)
        {
            return 0;
        }
        if (size < 2)
        {
            return singleRomanToInt(s[0]);
        }
        int result = 0;

        int window_start_ptr = 1;
        int window_end_ptr = 0;
        
        while (window_end_ptr < size)
        {   
            int start = singleRomanToInt(s[window_start_ptr]);
            int end = singleRomanToInt(s[window_end_ptr]);
            if (window_start_ptr > size)
            {
                result += start;
                break;
            }
            if (end >= start)
            {
                result += end;
                window_end_ptr++;
                window_start_ptr++;
                continue;
            }
            if (end < start)
            {
                result += (start - end);
                window_start_ptr += 2;
                window_end_ptr += 2;
            }
        }
        return result;
    }

    int singleRomanToInt(char chr) {
        int result = 0;
        switch (chr)
        {
        case 'I':
            result = 1;
            break;
        case 'V':
            result = 5;
            break;
        case 'X':
            result = 10;
            break;
        case 'L':
            result = 50;
            break;
        case 'C':
            result = 100;
            break;
        case 'D':
            result = 500;
            break;
        case 'M':
            result = 1000;
            break;
        }
        return result;
    }
};
// @lc code=end

int main(int argc, const char* argv[]) {
    Solution s;
    /// MMMCMXCIX
    int result = s.romanToInt("IVXLCDM");
    cout<<result<<endl;
    return 0;
}
