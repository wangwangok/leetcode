#include <vector>
using namespace std;

class Solution{
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();
        if (rows <= 0) return false;
        int columns = array[0].size();
        if (columns <= 0) return false;
        int row_idx = 0, col_idx = columns - 1;
        while(row_idx < rows && col_idx >= 0) 
        {
            int value = array[row_idx][col_idx];
            if (value == target) return true;
            else if (value > target) col_idx--;
            else row_idx++;
        }
        return false;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}