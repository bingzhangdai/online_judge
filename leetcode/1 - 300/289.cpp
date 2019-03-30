#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
*/

#define DIE2LIVE 0b10
#define DIE2DIE 0b00
#define LIVE2LIVE 0b11
#define LIVE2DIE 0b01
#define NEXT(x) ((x & 2) >> 1)

class Solution {
    int getLiveNeighbors(const vector<vector<int>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();
        int res = 0;
        for (int i = max(0, x - 1); i < min(m, x + 2); i++) {
            for (int j = max(0, y - 1); j < min(n, y + 2); j++) {
                res += board[i][j] & 1;
            }
        }
        return res - (board[x][y] & 1);
    }
    int getNextState(const vector<vector<int>>& board, int x, int y) {
        int neighbors = getLiveNeighbors(board, x, y);
        if (!board[x][y]){
            if (neighbors == 3)
                return DIE2LIVE;
            return DIE2DIE;
        }
        if (neighbors < 2 || neighbors > 3)
            return LIVE2DIE;
        return LIVE2LIVE;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = getNextState(board, i, j);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = NEXT(board[i][j]);
            }
        }
    }
};

int main(void) {
    return 0;
}
