#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        size_t r_size = ransomNote.size(), m_size = magazine.size();
        if (m_size <= 0 || r_size <= 0) {
            return false;
        }
        map<char, int> m_map;
        for (auto i : magazine) {
            m_map[i]++;
        }
        for (auto r : ransomNote) {
            if (m_map[r] < 1) {
                return false;
            } else {
                m_map[r]--;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    string ransomNote = "aa";
    string magazine = "b";
    cout << s.canConstruct(ransomNote, magazine) << endl;
    return 0;
}
