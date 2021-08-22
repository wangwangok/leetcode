#include <iostream>
#include <vector>

using namespace std;

/**
 * 
 * 给定一个数组，请你编写一个函数，返回该数组排序后的形式.
 * 输入：[5,2,3,1,4]
 * 输出：[1,2,3,4,5]
 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
        if (arr.size() <= 0) return {};
        int lhs = 0;
        int rhs = arr.size() - 1;
        partition(arr, lhs, rhs);
        return arr;
    }
private:
    void partition(vector<int> &arr, int lhs, int rhs) {
        if (lhs < 0 || lhs >= arr.size()) return;
        if (rhs < 0 || rhs >= arr.size()) return;
        if (lhs >= rhs) return;
        int p = lhs;
        int i = p + 1;
        int j = rhs;
        while (i < j) {
            while (arr[i] < arr[p] && i <= rhs) i++;
            while (arr[j] > arr[p] && j  >= lhs) j--;
            if (i < j) swap(arr, i, j);
        }
        if (arr[p] > arr[j]) swap(arr, p, j);
        partition(arr, lhs, j - 1);
        partition(arr, j + 1, rhs);
    }

    void swap(vector<int> &arr, int i, int j) {
        if (i == j) return;
        if (i < 0 || i >= arr.size()) return;
        if (j < 0 || j >= arr.size()) return;
        arr[i] ^= arr[j];
        arr[j] ^= arr[i];
        arr[i] ^= arr[j];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> arr = {5,1,6,2,5};
    vector<int> result = s.MySort(arr);
    cout<<"[";
    for (vector<int>::iterator itr = result.begin(); itr != result.end(); ++itr) {
        cout<<*itr<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}