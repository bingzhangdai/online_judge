#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.

Note:
The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
*/

class Solution {
    const int size = 9;
    vector<char> get_candidates(vector<vector<char>>& board, int row, int col) {
        auto counter = vector<int>(size, 0);
        auto appear = vector<int>(size, 0);
        for (auto i = 0; i < size; i++) {
            if (board[row][i] != '.') {
                // if (++counter[board[row][i] - '1'] > 1)
                //     return {};
                appear[board[row][i] - '1']++;
            }
        }
        for (auto i = 0; i < size; i++) {
            counter[i] = 0;
        }
        for (auto i = 0; i < size; i++) {
            if (board[i][col] != '.') {
                // if (++counter[board[i][col] - '1'] > 1)
                //     return {};
                appear[board[i][col] - '1']++;
            }
        }
        for (auto i = 0; i < size; i++) {
            counter[i] = 0;
        }
        for (auto i = (row / 3) * 3; i < (row / 3 + 1) * 3; i++) {
            for (auto j = (col / 3) * 3; j < (col / 3 + 1) * 3; j++) {
                if (board[i][j] != '.') {
                    // if (++counter[board[i][j] - '1'] > 1)
                    //     return {};
                    appear[board[i][j] - '1']++;
                }
            }
        }
        auto candidates = vector<char>();
        for (auto i = 0; i < size; i++) {
            if (!appear[i]) {
                candidates.push_back(i + '1');
            }
        }
        return candidates;
    }
    bool dfs(vector<vector<char>>& board, int row, int col) {
        while (row < size && board[row][col] != '.') {
            row += (col + 1) / size;
            col = (col + 1) % size;
        }
        if (row == size)
            return true;
        auto candidates = get_candidates(board, row, col);
        if (candidates.size() == 0)
            return false;
        for (auto c : candidates) {
            board[row][col] = c;
            if (dfs(board, row, col))
                return true;
        }
        board[row][col] = '.';
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }
};

int main(void) {
    vector<vector<char>> a = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    Solution().solveSudoku(a);
    cout << a[0][2] << endl;
    return 0;
}