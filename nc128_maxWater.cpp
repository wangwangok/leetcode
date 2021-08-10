#include <iostream>
#include <vector>

using namespace std;

/**
 * 给定一个整形数组arr，已知其中所有的值都是非负的，将这个数组看作一个柱子高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 */

/**
 * 输入：[3,1,2,5,2,4]
 * 输出：5
 * 说明：数组 [3,1,2,5,2,4] 表示柱子高度图，在这种情况下，可以接 5个单位的雨水，蓝色的为雨水
 */

class Solution {
public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    long long maxWater(vector<int>& arr) {
        if (arr.size() <= 0)
        {
            return 0;
        }
        int left = 0, right = arr.size() - 1;
        int min = arr[left] < arr[right] ? arr[left] : arr[right];
        long long sum = 0;
        while (left < right)
        {
            if (arr[left] < arr[right]) 
            {
                left++;
                if (arr[left] < min) 
                {
                    sum += min - arr[left];
                }
                else
                {
                    min = arr[left] < arr[right] ? arr[left] : arr[right];
                }
            }
            else 
            {
                right--;
                if (arr[right] < min) 
                {
                    sum += min - arr[right];
                }
                else
                {
                    min = arr[left] < arr[right] ? arr[left] : arr[right];
                }
            }
        }
        return sum;
    }
};

int main(int argc, const char *argvp[]) {
    Solution s;
    vector<int> vec = {3,1,2,5,2,4};
    cout<<s.maxWater(vec)<<endl;
}