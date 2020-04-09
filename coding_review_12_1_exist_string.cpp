#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    int str_idx = 0;
    vector<int> visited;
    bool findPath(vector<vector<char> >& board, string word, int row, int col) {
        if (word[str_idx] == '\0') return true;
        int row_nums = board.size();
        if (row_nums <= 0)
        {
            return false;
        }
        int col_nums = board[0].size();
        int size = word.size();
        if (size <= 0 || size > row_nums * col_nums)
        {
            return false;
        }
        if (row >= row_nums || row < 0) return false;
        if (col >= col_nums || col < 0) return false;
        if (visited[row*col_nums + col])
        {
            return false;
        }
        
        bool exist = false;
        if (board[row][col] != word[str_idx])
        {    
            return exist;    
        }
        str_idx++;
        visited[row * col_nums + col] = true;
        exist = findPath(board, word, row - 1, col) || findPath(board, word, row, col - 1) || findPath(board, word, row + 1, col) | findPath(board, word, row, col + 1);
        if (!exist)
        {
            str_idx--;
            visited[row * col_nums + col] = false;
        }
        return exist;
    }

public:
    bool exist(vector<vector<char> >& board, string word) {
        int row_nums = board.size();
        if (row_nums <= 0)
        {
            return false;
        }
        int col_nums = board[0].size();
        int size = word.size();
        if (size <= 0 || size > row_nums * col_nums)
        {
            return false;
        }
        vector<int> temp(row_nums * col_nums, 0); 
        visited = temp;
        for (int i = 0; i < row_nums; i++) {
            for (int j = 0; j < col_nums; j++ ) {
                bool find = findPath(board, word, i, j);
                if (find) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    vector<vector<char> >boards{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout<<s.exist(boards, word)<<endl;
    return 0;
}