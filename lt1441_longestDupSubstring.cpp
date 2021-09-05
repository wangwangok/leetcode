#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestDupSubstring(string s) {
        /*
        abcdabcda    bcefefbcef
        abcda bcda   bcefe fbcef
        */
        const size_t n = s.size();
        if (n <= 0) return "";
        int nums[n];
        for (int i = 0; i < n; i++) {
            nums[i] = s[i] - 'a';
        }
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

        }
    }

    int search(string s, int base) {

    }
};

int main(int argc, const char* argv[]) {

    return 0;
}