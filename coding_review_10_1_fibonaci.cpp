#include <iostream>

using namespace std;

class Solution {
public:
    int fibonaci(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        return fibonaci(n-1) + fibonaci(n-2);
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    cout<<s.fibonaci(4)<<endl;
    return 0;
}