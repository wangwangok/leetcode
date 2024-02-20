#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t size = prices.size();
        if (size <= 1) {
            return 0;
        }
        int in = prices[0];
        int out = 0;
        int profit = 0;
        for (int i = 1; i < size; i++) {
            if (in > prices[i]) {
                in = prices[i];
                out = 0;
            } else {
                if (out < prices[i]) {
                    out = prices[i];
                }
            }
            if (out >= in) {
                if (profit < (out - in)) {
                    profit = out - in;
                }
            }
        }
        return profit;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> prices = {2,4,1};
    int profit = s.maxProfit(prices);
    cout<<profit<<endl;
    return 0;
}
