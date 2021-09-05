#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        vector<int> fiblist = {0,1};
        if (n <= 1) return fiblist[n];
        for (int i = 2; i <= n; i++) {
            fiblist.push_back(fiblist[i-1] + fiblist[i-2]);
        }
        return fiblist[n];
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    cout<<s.Fibonacci(4)<<endl;
    return 0;
}