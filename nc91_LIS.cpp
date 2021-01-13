#include <iostream>
#include <vector>

using namespace std;

/*
 * 给定数组arr，设长度为n，输出arr的最长递增子序列。（如果有多个答案，请输出其中字典序最小的）
 * input: [1,2,8,6,4]
 * output:
 * desc: 其最长递增子序列有3个，（1，2，8）、（1，2，6）、（1，2，4）其中第三个字典序最小，故答案为（1，2，4）
*/

class Solution {
public:
    /**
     * retrun the longest increasing subsequence
     * @param arr int整型vector the array
     * @return int整型vector
     */
    vector<int> LIS(vector<int>& arr) {
        size_t size = arr.size();
        if (size < 2) return arr;
        vector<int> value = {arr[0]}, mLens = {1};
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > value.back()) 
            {
                value.push_back(arr[i]);
                mLens.push_back(value.size());
                continue;
            }
            for (int j = 0; j < value.size(); j++)
            {
                if (arr[i] <= value[j]) 
                {
                    value[j] = arr[i];
                    mLens.push_back(j+1);
                    break;
                }
            }
        }
        for (int i = mLens.size() - 1, j = value.size(); i >= 0 && j >= 0; i--)
        {
            if (mLens[i] == j) {
                value[--j] = arr[i];
            }
        }
        return value;
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    vector<int> in = {2,1,5,3,6,4,8,9,7};
    /**
     * i = 0, v:[2], m:[1]
     * i = 1, v:[1], m:[1,1]
     * i = 2, v:[1,5], m:[1,1,2]
     * i = 3, v:[1,3], m:[1,1,2,2]
     * i = 4, v:[1,3,6], m:[1,1,2,2,3]
     * i = 5, v:[1,3,4], m:[1,1,2,2,3,3]
     * i = 6, v:[1,3,4,8], m:[1,1,2,2,3,3,4]
     * i = 7, v:[1,3,4,8,9], m:[1,1,2,2,3,3,4,5]
     * i = 8, v:[1,3,4,7,9], m:[1,1,2,2,3,3,4,5,4] /// 这里是第4个的数字8被替换了，因此这里的长度更新为4
     */
    vector<int> out = s.LIS(in);
    cout<<"[";
    for (int i = 0; i < out.size(); i++)
    {
        cout<<out[i]<<", ";
    }
    cout<<"]";
    return 0;
}