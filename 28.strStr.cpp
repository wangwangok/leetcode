#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int strStr(string haystack, string needle) {
        size_t h_size = haystack.size(), n_size = needle.size();
        if (n_size > h_size || n_size < 1) {
            return -1;
        }
        int i = 0;
        for (int j = 0; j < h_size; j++) {
            if (needle[i] != haystack[j]) {
                j -= i;
                i = 0;
            } else {
                i++;
            }
            if (i >= n_size) {
                return j - (n_size - 1);
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    string haystack = "sadbutsad";
    string needle = "sad";
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}
