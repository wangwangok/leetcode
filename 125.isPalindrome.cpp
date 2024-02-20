#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        size_t size = s.size();
        if (size <= 0) return false;
        if (size == 1) return true;
        string result = "";
        for(auto c : s) {
            int convert = 'a' - 'A';
            if (c >= 'a' && c <= 'z') {
                result.push_back(c);
            } else if (c >= 'A' && c <= 'Z') {
                char ic = c + convert;
                result.push_back(ic);
            } else if (c >= '0' && c <= '9') {
                result.push_back(c);
            }
        }
        size = result.size();
        for (int i = 0, j = size - 1; i < size && j > 0 && i <= j; i++, j--) {
            if (result[i] != result[j]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "0P";
    //"race a car";
    //"A man, a plan, a canal: Panama";
    cout<<s.isPalindrome(str)<<endl;
    return 0;
}
