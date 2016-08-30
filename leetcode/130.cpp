#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0)
            return;
        int n = board[0].size();
        vector<vector<bool>> visited()
    }
};

int main(void) {
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