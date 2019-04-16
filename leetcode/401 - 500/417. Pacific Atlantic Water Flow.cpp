#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

class Solution {
    static const int PACIFIC = 0b01;
    static const int ATLANTIC = 0b10;
    int m, n;
    void watertop(deque<pair<int, int>>& flow, vector<vector<int>>& grid, vector<vector<int>>& matrix, int mark) {
        while (!flow.empty()) {
            auto& top = flow.front();
            grid[top.first][top.second] |= mark;
            if (top.first > 0 && matrix[top.first - 1][top.second] >= matrix[top.first][top.second] && !(grid[top.first - 1][top.second] & mark))
                flow.emplace_back(top.first - 1, top.second);
            if (top.second > 0 && matrix[top.first][top.second - 1] >= matrix[top.first][top.second] && !(grid[top.first][top.second - 1] & mark))
                flow.emplace_back(top.first, top.second - 1);
            if (top.first + 1 < m && matrix[top.first + 1][top.second] >= matrix[top.first][top.second] && !(grid[top.first + 1][top.second] & mark))
                flow.emplace_back(top.first + 1, top.second);
            if (top.second + 1 < n && matrix[top.first][top.second + 1] >= matrix[top.first][top.second] && !(grid[top.first][top.second + 1] & mark))
                flow.emplace_back(top.first, top.second + 1);
            flow.pop_front();
        }
    }
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>> & matrix) {
        if (matrix.empty() || matrix.front().empty())
            return {};
        m = matrix.size(), n = matrix.front().size();
        vector<vector<int>> grid(m, vector<int>(n, 0));
        deque<pair<int, int>> flow;
        for (int i = 0; i < m; i++) {
            flow.emplace_back(i, 0);
        }
        for (int j = 0; j < n; j++) {
            flow.emplace_back(0, j);
        }
        watertop(flow, grid, matrix, PACIFIC);
        for (int i = 0; i < m; i++) {
            flow.emplace_back(i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            flow.emplace_back(m - 1, j);
        }
        watertop(flow, grid, matrix, ATLANTIC);
        vector<pair<int, int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] & PACIFIC && grid[i][j] & ATLANTIC) {
                    res.emplace_back(i, j);
                }
            }
        }
        return res;
    }
};

int main(void) {
    return 0;
}
