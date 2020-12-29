#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    /**
     * max sum of the subarray
     * @param arr int整型vector the array
     * @return int整型
     */
    int sMax(int a, int b) {
        return a >= b ? a : b;
    }
    int maxsumofSubarray(vector<int>& arr) {
        int result = 0;
        if (arr.size() <= 0)
        {
            return result;
        }
        vector<int> sumArr;
        for (int i =  0; i < arr.size(); i++)
        {
            int sum;
            if (i == 0) 
            {
                sum = arr[i];
            }
            else 
            {
                sum = sMax(sumArr[i-1]+arr[i], arr[i]);
            } 
            result = sMax(result,sum);
            sumArr.push_back(sum);
        }
        return result;
    }
};

int main(int argc, const char **argv) {
    /// [1, -2, 3, 5, -2, 6, -1]
    /// [3,4,5,-2,6,7,8,-4,10]
    Solution s;
    vector<int> arr{3,4,5,-2,6,7,8,-4,10};
    cout<<s.maxsumofSubarray(arr)<<endl;
    return 0;
}