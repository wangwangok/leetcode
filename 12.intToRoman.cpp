#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
  public:
    string intToRoman(int num) {
        string result = "";
        map<int, string> i2r = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"},
        };
        /// 1 ~ 3999
        for (auto itr = i2r.rbegin(); itr != i2r.rend(); itr++) {
            pair<int, string> value = *itr;
            int count = num / value.first;
            if (count <= 0) {
                continue;
            }
            for (int i = 0; i < count; i++) {
                result.append(value.second);
            }
            num = num % value.first;
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    int num = 3999;
    // 1994;
    // 58;
    // 9;
    // 3;
    // 4;
    cout << solution.intToRoman(num) << endl;
    return 0;
}
