#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
  public:
    int romanToInt(string s) {
        map<char, int> romaMap = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                  {'C', 100}, {'D', 500}, {'M', 1000}};
        auto remake = [&s, &romaMap](int &i, bool need_r, char r1,
                                     char r2) -> int {
            char n = s[i + 1];
            char c = s[i];
            if (need_r && i < s.size() - 1) {
                if (n == r1 || n == r2) {
                    i++;
                    return romaMap[n] - romaMap[c];
                } else {
                    return romaMap[c];
                }
            } else {
                return romaMap[c];
            }
        };
        long long result = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            switch (c) {
            case 'I': {
                result += remake(i, true, 'V', 'X');
            } break;
            case 'X': {
                result += remake(i, true, 'L', 'C');
            } break;
            case 'C': {
                result += remake(i, true, 'D', 'M');
            } break;

            default: {
                result += remake(i, false, '0', '0');
            } break;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    string s = "MCMXCIV";
    //"LVIII";
    //"III";
    cout << solution.romanToInt(s) << endl;
    return 0;
}
