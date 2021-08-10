#include <iostream>
#include <vector>

/**
 * 
 * 假设你有一个数组，其中第 i 个元素是股票在第 i 天的价格。
 * 你有一次买入和卖出的机会。（只有买入了股票以后才能卖出）。请你设计一个算法来计算可以获得的最大收益。
*/

/**
 * 输入：[1,4,2]
 * 返回值：3
 */

/**
 * 输入：[2,4,1]
 * 返回值：2
 */

using namespace std;
class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        if (prices.size() <= 0) return maxP;
        for (vector<int>::iterator itr = prices.begin(); itr != prices.end(); ++itr) {
            for (vector<int>::iterator jtr = itr; jtr != prices.end(); ++jtr) {
                int val = *jtr - * itr;
                maxP = maxP < val ? val : maxP;
            }
        }
        return maxP;
    }

    int maxProfit2(vector<int>& prices) {
        int maxP = 0;
        if (prices.size() <= 0) return maxP;
        int lead = 0, min = 0;
        for (;lead < prices.size(); ++lead) {
            min = prices[lead] < prices[min] ? lead : min;
            int val = prices[lead] - prices[min];
            maxP = maxP < val ? val : maxP;
        }
        return maxP;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    vector<int>p = {2,4,1};
    cout<< s.maxProfit2(p) << endl;
    return 0;
}


