// #include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseStr(std::string& str) {
        int len = str.size();
        if (len < 2) return;
        int i = 0, j = len - 1;
        while(i < j && i < len && j > 0) {
            auto temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        }
    }

    int maximumNumberOfStringPairs(vector<string>& words) {
        int len = words.size();
        if (len < 2) {
            return 0;
        }
        int i = 0;
        int result = 0;
        vector<int> indexs(len, 0);
        while(i < len - 1){
            string r(words[i]);
            reverseStr(r);
            int j = len - 1;
            while(j > i){
                if (indexs[j] != 1 && r == words[j]) {
                    result++;
                    indexs[j] = 1;
                    indexs[i] = 1;
                } else {
                    j--;
                }
            }
            i++;
        }
        return result;
    }
};

int main(int argc, const char* argv[])
{
    
    return 0;
}