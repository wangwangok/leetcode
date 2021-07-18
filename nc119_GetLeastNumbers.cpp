#include <iostream>
#include <vector>
/*
描述

给定一个数组，找出其中最小的K个数。例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
0 <= k <= input.length <= 10000
0 <= input[i] <= 10000

## 示例1
输入：[4,5,1,6,2,7,3,8],4 
返回值：[1,2,3,4]
说明：
返回最小的4个数即可，返回[1,3,2,4]也可以  

## 示例2
输入：[1],0
返回值：[]

## 示例3
输入：[0,1,2,1,2],3
返回值：[0,1,1]
*/

using namespace std;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.size() <= 0)
        {
            return input;
        }
        input = sort(input);
        if (k <= 0)
        {
            return {};
        }
        if (k >= input.size())
        {
            return input;
        }
        
        vector<int> result(input.begin(),input.begin() + k);
        return result;
    }

    vector<int> sort(vector<int> input) {
        return partition(input, 0, input.size() - 1);
    }

private:
    void swap(vector<int> &input, int lhs, int rhs) {
        if (lhs >= input.size() || rhs >= input.size() || lhs == rhs)
        {
            return;
        }
        input[lhs] ^= input[rhs];
        input[rhs] ^= input[lhs];
        input[lhs] ^= input[rhs];
    }

    vector<int> partition(vector<int> &input, int lhs, int rhs) {
        if (lhs >= rhs)
        {
            return input;
        }
        int pivot = lhs;
        int start = lhs + 1;
        int end = rhs;

        while (start < end)
        {
            while (input[start] <= input[pivot] && start < rhs)
            {
                start++;
            }
            while (input[end] > input[pivot] && end >= lhs)
            {
                end--;
            }
            if (start <= end)
            {
                swap(input, start, end);
            }
        }
        if (input[pivot] > input[end])
        {
            swap(input, pivot, end);
        }
        partition(input, lhs, end-1);
        partition(input, end+1, rhs);
        return input;
    }
};

int main(int argc, const char* argv[]) {
    // vector<int> inputs = {234,233,233,233,233,233,233,233,233,233,233,233,233,233,233,233,233,233,233,233};
    vector<int> inputs = {0,1,2,1,2};
    Solution s;
    vector<int> result = s.GetLeastNumbers_Solution(inputs, 3);
    for (vector<int>::iterator itr = result.begin(); itr != result.end(); ++itr)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;
    return 0;
}