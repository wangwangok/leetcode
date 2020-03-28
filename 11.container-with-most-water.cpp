/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_size = 0;
        if (height.size() <= 0)
        {
            return max_size;
        }
        vector<int>::iterator itr = height.begin();
        vector<int>::iterator ritr = height.end() - 1;
        int width = ritr - itr;
        do {
            int height = 0;
            if (*itr <= *ritr)
            {
                height = *itr;
                itr++;
            }
            else
            {
                height = *ritr;
                ritr--;
            }
            int size = width * height;
            max_size = max_size > size ? max_size : size;
            width = ritr - itr;
        } while (width >= 0);
        return max_size;
    }
};
// @lc code=end

int main(int argc, const char *argv[]) {
    Solution s;
    int array[8] = {1,8,6,2,5,4,8,3};
    vector<int> height(array,array+8);
    int result = s.maxArea(height);
    cout<<result<<endl;
    return 0;    
}
