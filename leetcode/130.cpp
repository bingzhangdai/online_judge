#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
//run time error, maybe stack overflow
class Solution {
    bool dfs(const vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, int m, int n) {
        if (board[i][j] == 'X' || visited[i][j])
            return true;
        visited[i][j] = true;
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
            return false;
        auto res = true;
        // here order matters
        res = dfs(board, i - 1, j, visited, m, n) && res;
        res = dfs(board, i + 1, j, visited, m, n) && res;
        res = dfs(board, i, j + 1, visited, m, n) && res;
        res = dfs(board, i, j - 1, visited, m, n) && res;
        return res;
    }

    void change_O_2_X(vector<vector<char>>& board, int i, int j, int m, int n) {
        board[i][j] = 'X';
        if (board[i-1][j] == 'O')
            change_O_2_X(board, i - 1, j, m, n);
        if (board[i+1][j] == 'O')
            change_O_2_X(board, i + 1, j, m, n);
        if (board[i][j-1] == 'O')
            change_O_2_X(board, i, j - 1, m, n);
        if (board[i][j+1] == 'O')
            change_O_2_X(board, i, j + 1, m, n);
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0)
            return;
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    if (dfs(board, i, j, visited, m, n))
                        change_O_2_X(board, i, j, m, n);
                }
            }
        }
    }
};
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
    }
};

int main(void) {
    vector<vector<char>> board = {{'O', 'O', 'O', 'O', 'O'},
                                  {'O', 'X', 'X', 'X', 'O'},
                                  {'O', 'X', 'O', 'X', 'O'},
                                  {'O', 'X', 'X', 'X', 'O'},
                                  {'O', 'O', 'O', 'O', 'O'}};
    Solution().solve(board);
    return 0;
}

/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region. 
For example,
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be: 
X X X X
X X X X
X X X X
X O X X
*/
