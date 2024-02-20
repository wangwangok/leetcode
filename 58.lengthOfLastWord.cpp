#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int lengthOfLastWord(string s) {
        vector<string> words;
        string tempStr = "";
        for (string::iterator itr = s.begin(); itr != s.end(); itr++) {
            char c = *itr;
            if (c != ' ') {
                tempStr.push_back(c);
            } else {
                if (tempStr.size() > 0) {
                    words.push_back(tempStr);
                    tempStr = "";
                }
            }
        }
        if (tempStr.size() > 0) {
            words.push_back(tempStr);
            tempStr = "";
        }
        if (words.size() < 1)
            return 0;
        return words[words.size() - 1].size();
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    string s =
        // "Hello World";
        // "   fly me   to   the moon  ";
        // "luffy is still joyboy";
        cout << solution.lengthOfLastWord(s) << endl;
    return 0;
}
