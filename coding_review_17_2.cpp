#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void twoBigNumSum(long long lhs, long long rhs) {
        vector<char> ans;
        int carryin = 0;
        for (;lhs != 0 || rhs != 0 || carryin == 1;lhs = lhs / 10, rhs = rhs / 10)
        {
            int sum = (lhs % 10) + (rhs % 10) + carryin;
            if (sum >= 10)
            {
                carryin = 1;
                sum = sum - 10;
                ans.push_back(sum+'0');
            }
            else
            {
                ans.push_back(sum+'0');
                carryin = 0;
            }
        }
        for(vector<char>::const_reverse_iterator r_itr = ans.rbegin(); r_itr != ans.rend(); ++r_itr) {
            cout<<*r_itr;
        }
        cout<<endl;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    s.twoBigNumSum(7979797275942,860285042840);
    return 0;
}