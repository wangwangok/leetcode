#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fibonacci(int n) {
        vector<int> result{0,1};
        if (n < 2) return result[n];
        int lhs = result[0];
        int rhs = result[1];
        long long ans = 0;
        long long mask = 1e9+7;
        for (int i = 2; i <= n; i++ )
        {
            ans = (lhs + rhs) % mask;
            lhs = rhs;
            rhs = ans;
        }
        return ans % mask;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    cout<<s.fibonacci(45)<<endl;
    return 0;
}