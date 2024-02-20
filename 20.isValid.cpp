#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    bool make_pair(string &c_s, const string &s, int idx) {
        if (idx >= s.size()) {
            return false;
        }
        auto c = s[idx];
        size_t size = c_s.size();
        if (size < 1) {
            c_s.push_back(c);
            return make_pair(c_s, s, idx + 1);
        }
        switch (c) {
        case ')': {
            if (size > 0 && c_s[size - 1] == '(') {
                c_s.pop_back();
                return true;
            } else {
                return false;
            }
        };
        case ']': {
            if (size > 0 && c_s[size - 1] == '[') {
                c_s.pop_back();
                return true;
            } else {
                return false;
            }
        };
        case '}': {
            if (size > 0 && c_s[size - 1] == '{') {
                c_s.pop_back();
                return true;
            } else {
                return false;
            }
        };
        default: {
            c_s.push_back(c);
            return make_pair(c_s, s, idx + 1);
        }
        }
        return false;
    }

  public:
    bool isValid(string s) {
        size_t s_size = s.size();
        if (s_size <= 0)
            return false;
        int idx = 0;
        vector<char> stack;
        for (auto c : s) {
            size_t size = stack.size();
            switch (c) {
            case ')': {
                if (size > 0 && stack[size - 1] == '(') {
                    stack.pop_back();
                } else {
                    stack.push_back(c);
                }
                break;
            };
            case ']': {
                if (size > 0 && stack[size - 1] == '[') {
                    stack.pop_back();
                } else {
                    stack.push_back(c);
                }
                break;
            };
            case '}': {
                if (size > 0 && stack[size - 1] == '{') {
                    stack.pop_back();
                } else {
                    stack.push_back(c);
                }
                break;
            };
            default: {
                stack.push_back(c);
            } break;
            }
        }
        return stack.size() == 0;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    string str =
        // "{}}{";
        "]";
    // "({[)()]}[])";
    // "({}[])";
    // "(]";
    // "()[]{}";
    // "()";
    cout << s.isValid(str) << endl;
    return 0;
}
