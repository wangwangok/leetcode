#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

/**
给出一个有n个元素的数组S，S中是否有元素a,b,c满足a+b+c=0？找出数组S中所有满足条件的三元组。
注意：
    三元组（a、b、c）中的元素必须按非降序排列。（即a≤b≤c）
    解集中不能包含重复的三元组。
例如，给定的数组 S = {-10 0 10 20 -10 -40},解集为(-10, -10, 20),(-10, 0, 10) 
    0 <= S.length <= 1000
*/

/*
输入: [-2,0,1,1,2]
返回值: [[-2,0,2],[-2,1,1]]

输入: [-10,0,10,20,-10,-40]
返回值: [[-10,-10,20],[-10,0,10]]
*/

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        if (num.size() <= 0) return result;
        for (vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr) {
            int v = *itr;
            if (itr - num.begin() > 0 && *itr == *(itr-1))
            {
                continue;
            }
            int target = v * -1;
            vector<int>::iterator lhs = itr+1;
            vector<int>::iterator rhs = num.end() - 1;
            while (rhs - lhs > 0)
            {
                int sum = *lhs + *rhs;
                if (sum < target) {
                    ++lhs;
                } else if (sum > target) {
                    --rhs;
                } else {
                    vector<int> templist = {*itr, *lhs, *rhs};
                    result.push_back(templist);
                    while (rhs - lhs > 0 && *lhs == *(lhs + 1)) {
                        ++lhs;
                    }
                    while (rhs - lhs > 0 && *rhs == *(rhs - 1)) {
                        --rhs;
                    }
                    lhs++;
                    rhs--;
                }
            }
        }
        return result;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    vector<int> num = {0,0,0,0};
    vector<vector<int> > result = s.threeSum(num);
    for (vector<vector<int> >::iterator itr = result.begin(); itr != result.end(); ++itr) {
        vector<int> list = *itr;
        cout<<"[";
        for (vector<int>::iterator jtr = list.begin(); jtr != list.end(); ++jtr) {
            cout<<*jtr<<", ";
        }
        cout<<"]";
        cout<<endl;
    }
    return 0;
}