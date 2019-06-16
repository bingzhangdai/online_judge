#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> islands;
        if (grid.empty() || grid.front().empty())
            return 0;
        auto m = grid.size(), n = grid.front().size();
        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                grid[i][j] = 0;
                string encode = "";
                // bfs
                deque<pair<int, int>> neighbors{ {i, j} };
                while (!neighbors.empty()) {
                    auto x = neighbors.front().first, y = neighbors.front().second;
                    neighbors.pop_front();
                    encode += to_string(x - i) + to_string(y - j);
                    if (x > 0 && grid[x - 1][y]) {
                        grid[x - 1][y] = 0;
                        neighbors.emplace_back(x - 1, y);
                    }
                    if (y > 0 && grid[x][y - 1]) {
                        grid[x][y - 1] = 0;
                        neighbors.emplace_back(x, y - 1);
                    }
                    if (x < m - 1 && grid[x + 1][y]) {
                        grid[x + 1][y] = 0;
                        neighbors.emplace_back(x + 1, y);
                    }
                    if (y < n - 1 && grid[x][y + 1]) {
                        grid[x][y + 1] = 0;
                        neighbors.emplace_back(x, y + 1);
                    }
                }
                islands.insert(encode);
            }
        }
        return islands.size();
    }
};

int main(void) {
    return 0;
}
