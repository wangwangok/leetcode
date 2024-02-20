#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> result{};
        size_t size = words.size();
        if (size < 1) {
            return result;
        }
        for (string str : words)
        {
            string dst;
            for (auto c : str)
            {
                if (c == separator) {
                    if (dst != "") {
                        result.push_back(dst);
                    }
                    dst = "";
                } else {
                    dst.push_back(c);
                }
            }
            if (dst != "") {
                result.push_back(dst);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> vs = {"one.two.three","four.five","six"};
    char c = '$';
    vector<string> rs = s.splitWordsBySeparator(vs, c);
    for (auto str:rs)
    {
        cout<<str<<endl;
    }
    return 0;
}
