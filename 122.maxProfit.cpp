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
        int total_profit = 0;
        for (int i = 1; i < size; i++) {
            int p = prices[i] - prices[i - 1];
            if (p > 0) {
                total_profit += p;
            }
        }
        return total_profit;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> prices = {7,6,4,3,1};
    int profit = s.maxProfit(prices);
    cout<<profit<<endl;
    return 0;
}