/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        string result;
        const int size = 13;
        int nums[size] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string roman[size] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int times = 10;
        int current = 1;
        int step = 0;
        while (num > 0)
        {
            int value = (num % times) * current;
            int base = 4 * step;
            int upper = 4+base-1 > size-1 ? size-1 : 4+base-1;
            string temp_result;
            for (int i = upper; i >= base  && i >= 0; i--)
            {
                if (value == nums[i])
                {
                    temp_result = temp_result.append(roman[i]);
                    break;
                }
                else if (value > nums[i])
                {
                    temp_result = temp_result.append(roman[i]);
                    int loop = (value-nums[i])/current;
                    for (int  k = 0; k < loop; k++)
                    {
                        temp_result = temp_result + roman[base];
                    }
                    break;
                }
            }
            result = temp_result + result;
            num = num / times;
            current *= times;
            step++;
        }
        return result;
    }
};
// @lc code=end

int main(int argc, const char* argv[]) {
    Solution s;
    string result = s.intToRoman(3999);
    cout<<result<<endl;
    return 0;
}
