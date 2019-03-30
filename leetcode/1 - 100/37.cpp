#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    const int num = 9;
    bool isValidSudoku(vector<vector<char>>& board) {
        auto count = vector<int>(num, 0);
        // row
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++)
                if (board[i][j] != '.' && ++count[board[i][j] - '1'] > 1)
                    return false;
            for (int j = 0; j < num; j++)
                count[j] = 0;
        }
        // column
        for (int j = 0; j < num; j++) {
            for (int i = 0; i < num; i++)
                if (board[i][j] != '.' && ++count[board[i][j] - '1'] > 1)
                    return false;
            for (int i = 0; i < num; i++)
                count[i] = 0;
        }
        // sub-box
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                int row = (i / 3) * 3 + j / 3, col = (i % 3) * 3 + j % 3;
                if (board[row][col] != '.' && ++count[board[row][col] - '1'] > 1)
                    return false;
            }
            for (int k = 0; k < num; k++)
                count[k] = 0;
        }
        return true;
    }
    void nextdot(vector<vector<char>>& board, int& row, int& col) {
        while (row < num && board[row][col] != '.') {
            row += (col + 1) / num;
            col = (col + 1) % num;
        }
    }

    bool dfs(vector<vector<char>>& board, int row, int col) {
        nextdot(board, row, col);
        if (row == num)
            return true;
        for (int i = 0; i < num; i++) {
            board[row][col] = i + '1';
            if (isValidSudoku(board)) {
                if (dfs(board, row, col))
                    return true;
            }
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
    vector<vector<char>> a = { {'.','8','7','6','5','4','3','2','1'}, {'2','.','.','.','.','.','.','.','.'}, {'3','.','.','.','.','.','.','.','.'}, 
        {'4','.','.','.','.','.','.','.','.'}, {'5','.','.','.','.','.','.','.','.'}, {'6','.','.','.','.','.','.','.','.'}, 
        {'7','.','.','.','.','.','.','.','.'}, {'8','.','.','.','.','.','.','.','.'}, {'9','.','.','.','.','.','.','.','.'} };
    Solution().solveSudoku(a);
    cout << a[0][0] << endl;
    system("pause");
    return 0;
}
