/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool sIsdigit(char c){
        return c>='0'&&c<='9';
    }

    int myAtoi(string str) {
        int int_min_l = 0x80000000;
        int int_max_l = 0x7fffffff;
        int signed_bit = 0;
        int64_t absValue = -1;
        for (string::iterator i = str.begin(); i != str.end(); ++i)
        {
            if (sIsdigit(*i))
            {
                if (absValue < 0)
                {
                    absValue = 0;
                }
                if (absValue > int_max_l)
                {
                    break;
                }
                uint8_t digit = *i - '0';
                absValue = absValue * 10 + digit;
            }
            else if (*i == 9 || *i == 32)
            { /// 9 tab, 32 space 
                if (absValue != -1 || signed_bit != 0)
                {
                    break;
                }
                continue;
            }
            else if (*i == '-')
            { /// minus number
                if (signed_bit == 0 && absValue == -1)
                {
                    signed_bit = -1;
                }
                else
                {
                    break;
                } 
            }
            else if (*i == '+')
            {
               if (signed_bit == 0 && absValue == -1)
               {
                   signed_bit = 1; 
               }
               else
               {
                   break;
               }
            }
            else
            {
                if (absValue <= 0)
                {
                    return 0;
                }
                break;
            }
        }
        if (absValue < 0)
        {
            absValue = 0;
        }
        int64_t temp = signed_bit == 0 ? absValue : signed_bit*absValue;
        if (temp < int_min_l)
        {
            return int_min_l; 
        }
        if (temp > int_max_l)
        {
            return int_max_l;
        }
        int32_t result = temp&0xffffffff;
        return result;
    }
};

// @lc code=end

int main(int argc, const char* argv[]) {
    Solution s;
    int result = s.myAtoi("    -42");
    std::cout<<"atoi: "<<result<<std::endl;
    return 0;
}