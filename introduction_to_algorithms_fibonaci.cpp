#include <iostream>
#include <vector>

using namespace std;
class Solution {
    public:
    int fibonaci(int n) {
        int start[2] = {1,1};
        if (n < 2)
        {
            return start[n];
        }
        vector <int> list(n+1,0);
        list[0] = start[0];
        list[1] = start[1];
        
        for (int i = 2; i <= n; i++)
        {
            int result = 0;
            for (int j = i - 2; j < i; j++)
            {
                result += list[j];
            }
            list[i] = result;
        }
        return list[n];
    }
};

int main() {
    Solution s;
    int result = s.fibonaci(6);
    cout<<result<<endl;
    return 0;
}