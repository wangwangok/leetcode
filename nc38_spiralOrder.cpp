#include <iostream>
#include <vector>

using namespace std;

/*
 * 给定一个 m x n 大小的矩阵（m行，n列），按螺旋的顺序返回矩阵中的所有元素。
 * 输入：[[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        int i = 0, j = -1, col = matrix[0].size(), row = matrix.size();
        int factor = 1;
        int total_count = col * row;
        while (col >= 0 && row >= 0 && result.size() < total_count)
        {
            
            int m = 0;
            do {
                if (result.size() == total_count) break;
                j=(j+factor);
                result.push_back(matrix[i][j]);
                m++;
            } while (m < col);
            
            int n = 0;
            do {
                if (result.size() == total_count) break;
                i=(i+factor);
                result.push_back(matrix[i][j]);
                n++;
            } while (n < row-1);
            col--;
            row--;
            factor = factor * -1;
        }
        return result;
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    vector<vector<int>> value{{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18}, {19,20,21,22,23,24}, {25,26,27,28,29,30},{31,32,33,34,35,36}};
    vector<int> inner={};
    // vector<vector<int>> value{inner};
    vector<int> result = s.spiralOrder(value);
    cout<<"[";
    for (int i = 0; i < result.size();i ++)
    {
        cout<<result[i]<<", ";
    }
    cout<<"]";
    return 0;
}