/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
    vector<string> ans;

    static unordered_map<char, string>number_map() {
        static unordered_map<char,string> maps = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        return maps;
    }

    void combinations_core(string& digit_bits, string& combination) {
        size_t size = digit_bits.size();
        if (size <= 0)
        {
            ans.push_back(combination);
            return;
        }
        string letters = number_map().find(digit_bits[0])->second;
        string param = digit_bits;
        param = param.substr(1,size-1);
        for(string::iterator c_itr = letters.begin(); c_itr != letters.end(); ++c_itr)
        {
            string str(1, *c_itr);
            string n_c = combination+str;
            combinations_core(param, n_c);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        size_t size = digits.size();
        if (size <= 0)
        {
            return {};
        }
        string str("");
        combinations_core(digits, str);
        return ans;
    }
};
// @lc code=end

int main(int argc, const char* argv[]) {
    Solution s;
    vector<string> ans = s.letterCombinations("234");
    for (vector<string>::iterator itr = ans.begin(); itr != ans.end(); ++itr)
    {
        cout<<*itr<<endl;
    }
    return 0;
}