#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    bool isvalid(const vector<vector<char>>& board, const vector<vector<bool>>& visited, const string& word, int ind, int i, int j, int m, int n) {
        return i >= 0 && i <m && j >= 0 && j < n && !visited[i][j] && board[i][j] == word[ind];
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, const string& word, int ind, int r, int c, int m, int n) {
        if (ind == word.size())
            return true;
        if (isvalid(board, visited, word, ind, r - 1, c, m, n)) {
            visited[r - 1][c] = true;
            if (dfs(board, visited, word, ind + 1, r - 1, c, m, n))
                return true;
            visited[r - 1][c] = false;
        }
        if (isvalid(board, visited, word, ind, r + 1, c, m, n)) {
            visited[r + 1][c] = true;
            if (dfs(board, visited, word, ind + 1, r + 1, c, m, n))
                return true;
            visited[r + 1][c] = false;
        }
        if (isvalid(board, visited, word, ind, r, c + 1, m, n)) {
            visited[r][c + 1] = true;
            if (dfs(board, visited, word, ind + 1, r, c + 1, m, n))
                return true;
            visited[r][c + 1] = false;
        }
        if (isvalid(board, visited, word, ind, r, c - 1, m, n)) {
            visited[r][c - 1] = true;
            if (dfs(board, visited, word, ind + 1, r, c - 1, m, n))
                return true;
            visited[r][c - 1] = false;
        }
        return false;
    }
        
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        bool isfound = false;
        auto visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isvalid(board, visited, word, 0, i, j, m, n)) {
                    visited[i][j] = true;
                    isfound = dfs(board, visited, word, 1, i, j, m, n);
                    if (isfound)
                        break;
                    visited[i][j] = false;
                }
            }
            if (isfound)
                break;
        }
        return isfound;
    }
};


int main(void) {
    vector<vector<char>> board {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    cout << Solution().exist(board, "ABCCED") << endl;
    // system("pause");
    return 0;
}
/*
Given a 2D board and a word, find if the word exists in the grid. 
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once. 
For example,
Given board = 
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
