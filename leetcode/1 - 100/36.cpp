#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int num = 9;
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
};

int main(void) {
    vector<vector<char>> a = { {'.','8','7','6','5','4','3','2','1'}, {'2','.','.','.','.','.','.','.','.'}, {'3','.','.','.','.','.','.','.','.'}, 
        {'4','.','.','.','.','.','.','.','.'}, {'5','.','.','.','.','.','.','.','.'}, {'6','.','.','.','.','.','.','.','.'}, 
        {'7','.','.','.','.','.','.','.','.'}, {'8','.','.','.','.','.','.','.','.'}, {'9','.','.','.','.','.','.','.','.'} };
    cout << Solution().isValidSudoku(a) << endl;
    system("pause");
    return 0;
}
