#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
    private:
    void invalidPostion(vector<int>& pos, const string& str) {
        size_t size = str.size();
        if (size <= 0)
        {
            return;
        }
        int tail = 0;
        int lead = 1;
        while (lead < size)
        {
            if (tail > 0 && str[lead] != str[tail])
            {
                tail = pos[tail];
                continue;
            }
            if (str[lead] == str[tail])
            {
                tail++;
                
                pos[lead] = tail;
            }
            else
            {    
                pos[lead] = 0;
            }
            lead++;
        }
    }

    public:
    int kmp(string& text, string& pattern) {
        int offset = 0;
        size_t text_size = text.size();
        size_t pattern_size = pattern.size();
        if (text_size < pattern_size)
        {
            return offset;
        }
        vector<int>invalids(pattern_size,0);
        invalidPostion(invalids,pattern); 
        int invlid_idx = 0;
        for (int i = 0; i < text_size; i++)
        {
            while (invlid_idx > 0 && text[i] != pattern[invlid_idx])
            {
                invlid_idx = invalids[invlid_idx - 1];
            }
            
            if (text[i] == pattern[invlid_idx])
            {
                invlid_idx++;
            }
            if (invlid_idx == pattern_size)
            {
                offset = i - invlid_idx + 1;
            }
        }
        
        return offset;
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    string text("bcbababaababacacd");
	string pattern("ababaca");
    int offset = s.kmp(text, pattern);
    return 0;
}
