#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int size = 9, block = 3;
        vector<int> counter(size, 0);
        for (auto i = 0; i < size; i++) {
            for (auto j = 0; j < size; j++) {
                if (board[i][j] != '.' && ++counter[board[i][j] - '1'] > 1)
                    return false;
            }
            for (auto j = 0; j < size; j++)
                counter[j] = 0;
        }
        for (auto i = 0; i < size; i++) {
            for (auto j = 0; j < size; j++) {
                if (board[j][i] != '.' && ++counter[board[j][i] - '1'] > 1)
                    return false;
            }
            for (auto j = 0; j < size; j++)
                counter[j] = 0;
        }
        for (auto i = 0; i < size; i++) {
            for (auto j = 0; j < size; j++) {
                auto ii = i / block * block  + j / block, jj = (i % block) * block + j % block;
                if (board[ii][jj] != '.' && ++counter[board[ii][jj] - '1'] > 1)
                    return false;
            }
            for (auto j = 0; j < size; j++)
                counter[j] = 0;
        }
        return true;
    }
};

int main(void) {
    vector<vector<char>> a = { {'.','8','7','6','5','4','3','2','1'}, {'2','.','.','.','.','.','.','.','.'}, {'3','.','.','.','.','.','.','.','.'}, 
        {'4','.','.','.','.','.','.','.','.'}, {'5','.','.','.','.','.','.','.','.'}, {'6','.','.','.','.','.','.','.','.'}, 
        {'7','.','.','.','.','.','.','.','.'}, {'8','.','.','.','.','.','.','.','.'}, {'9','.','.','.','.','.','.','.','.'} };
    cout << Solution().isValidSudoku(a) << endl;
    return 0;
}
