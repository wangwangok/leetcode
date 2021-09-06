#include <iostream>
#include <vector>

using namespace std;

/**
 * 描述：你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。
 * 
 * 示例 1:
 *      输入: [4, 1, 8, 7]
 *      输出: True
 *      解释: (8-4) * (7-1) = 24
 * 
 * 示例 2:
 *      输入: [1, 2, 1, 2]
 *      输出: False
 */

class Solution {
private:
    
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> dCards(cards.begin(), cards.end());
        if (dCards.size() == 0) {
            return false;
        }
        return dfs(dCards);
    }

private:
    bool dfs(vector<double> &cards) {
        int target = 24;
        if (cards.size() == 1) {
            return fabs(cards[0] - target) < 1e-6;
        }
        /// 先取两个数字
        size_t size = cards.size();
        for (int i = 0; i < size; i++) { /// 第一个数字
            for (int j = 0; j < size; j++) { /// 第二个数字
                if (i == j) continue;
                vector<double> temp_cards;
                for (int m = 0; m < size; m++) {
                    if (m != i && m != j) {
                        temp_cards.push_back(cards[m]);
                    }
                }
                /// + - * /
                for (int op = 0; op < 4; op++) {
                    double val = 0.0;
                    if (op == 0) {
                        val = cards[i] + cards[j];
                    } else if (op == 1) {
                        val = cards[i] - cards[j];
                    } else if (op == 2) {
                        val = cards[i] * cards[j];
                    } else if (op == 3) {   
                        val = cards[i] / cards[j];
                    }
                    temp_cards.push_back(val);
                    if (dfs(temp_cards)) {
                        return true;
                    }
                    temp_cards.pop_back();
                }
            }
        }
        return false;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    vector<int> cards = {8,3,3,8};
    //{1,2,1,2}; // false
    //{7,2,1,10}; // true
    //{4,1,8,7}; // true
    cout<<s.judgePoint24(cards)<<endl;
    return 0;
}