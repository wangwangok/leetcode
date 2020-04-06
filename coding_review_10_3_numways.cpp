#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numWays(int n) {
        if (n <= 0) return 0;
        vector<int> dp{0,1,2};
        int mask = 1e9+7;
        for (size_t i = 3; i <= n; i++)
        {
            int sum = (dp[i-1] + dp[i-2]) % mask;
            dp.push_back(sum);
        }
        return dp[n];
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    cout<<s.numWays(9)<<endl;
    return 0;
}