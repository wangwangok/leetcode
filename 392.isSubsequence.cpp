#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    size_t t_size = t.size();
    size_t s_size = s.size();
    if (s_size > t_size) {
      return false;
    }
    int start = 0, is = 0;
    for (int i = 0; i < s_size; i++) {
      for (int j = start; j < t_size; j++) {
        if (t[j] == s[i]) {
          start = j + 1;
          is = i;
          break;
        }
      }
      if (is != i) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  Solution solution;
  string t = "ahbgdc";
  //"ahbgdc";
  string s = "bb";
  // "abc";
  // "axc";
  cout << solution.isSubsequence(s, t) << endl;
  return 0;
}
