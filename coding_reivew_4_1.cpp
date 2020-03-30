#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool matrixContain(vector<vector<int> >matrixs, int target) {
        int rows = matrixs.size();
        if (rows <= 0) return false;
        int cols = matrixs[0].size();
        if (cols <= 0) return false;

        for (int col_num = cols - 1, row_num = 0; col_num >= 0 && row_num < rows;)
        {
            if (target == matrixs[row_num][col_num])
            {
                return true;
            }
            if (target > matrixs[row_num][col_num])
            {
                row_num++;
                continue;
            }
            if (target < matrixs[row_num][col_num])
            {
                col_num--;
            }
        }
        return false;
    }
};

int main(int argc, const char* argv[]) {
    vector<vector<int> > nums;
    vector<int> row1{1,2,8,9};
    nums.push_back(row1);
    vector<int> row2{2,4,9,112};
    nums.push_back(row2);
    vector<int> row3{4,7,10,13};
    nums.push_back(row3);
    vector<int> row4{6,8,11,15};
    nums.push_back(row4);

    Solution s;
    bool result = s.matrixContain(nums,30);
    cout<<result<<endl;
    return 0;
}