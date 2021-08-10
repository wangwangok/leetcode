#include <iostream>
#include <vector>
#include <unordered_map>


/**
 整给定一个整型数组 arr 和一个数 k(k>1)。已知 arr 中只有 1 个数出现一次，其他的数都出现 k 次。请返回只出现了 1 次的数。 
*/

/**
 * [5,4,1,1,5,1,5],3 
 */

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param arr intvector 
     * @param k int 
     * @return int
     */
    int foundOnceNumberForMap(vector<int>& arr, int k) {
        
        unordered_map<int, int> nums;
        for (vector<int>::iterator itr = arr.begin(); itr != arr.end(); ++itr) {
            unordered_map<int, int>::iterator res = nums.find(*itr);
            if (res != nums.end())
            {
                int val = res->second;
                res->second = val + 1;
            }
            else 
            {
                nums.insert({*itr, 1});
            }
        }
        for (unordered_map<int, int>::iterator itr = nums.begin(); itr != nums.end(); ++itr) 
        {
            if (itr->second == 1) {
                return itr->first;
            }
        }
        return 0;
    }

    int foundOnceNumberForBit(vector<int>& arr, int k) {
        int result = 0;
        if (arr.size() <= 0)
        {
            return result;
        }
        const int intlength = sizeof(int) * 8;
        int zbits[intlength] = {0};
        if (k % 2 ==0)
        {
            for (vector<int>::iterator itr = arr.begin(); itr != arr.end(); ++itr)
            {
                result ^= *itr;
            }
            return result;
        }
        for (int i = 0; i < intlength; i++) {
            int bits = 0;
            for (vector<int>::iterator itr = arr.begin(); itr != arr.end(); ++itr)
            {
                bits += (((*itr)>>i)&1);
            }
            zbits[i] = bits;
        }
        for (int i = 0; i < intlength; i++) {
            result |= ((zbits[i]%k) != 0) << i;
        }
        return result;
    }
};

int main(int argc, const char* argv[]) {

    Solution s;
    vector<int> arr = {5,4,1,1,5,1,5};
    cout<< s.foundOnceNumberForBit(arr, 3) << endl;
}