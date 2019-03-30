#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        queue<int> bfs;
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    bfs.push(i);
                    bfs.push(j);
                    while (!bfs.empty()) {
                        int x = bfs.front();
                        bfs.pop();
                        int y = bfs.front();
                        bfs.pop();
                        grid[x][y] = '0';
                        if (x > 0 && grid[x-1][y] == '1') {
                            grid[x-1][y] = '0';
                            bfs.push(x - 1);
                            bfs.push(y);
                        }
                        if (x < m - 1 && grid[x+1][y] == '1') {
                            grid[x+1][y] = 0;
                            bfs.push(x + 1);
                            bfs.push(y);
                        }
                        if (y > 0 && grid[x][y-1] == '1') {
                            grid[x][y-1] = '0';
                            bfs.push(x);
                            bfs.push(y - 1);
                        }
                        if (y < n - 1 && grid[x][y+1] == '1') {
                            grid[x][y+1] = '0';
                            bfs.push(x);
                            bfs.push(y + 1);
                        }
                    }
                    res++;
                }
            }
        }
        return res;
    }
};

int main(void) {
    return 0;
}
