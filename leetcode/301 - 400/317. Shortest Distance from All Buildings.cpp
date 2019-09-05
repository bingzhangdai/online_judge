#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
I walk only onto the cells that were reachable from all previous buildings.
From the first building I only walk onto cells where grid is 0, and make them -1.
From the second building I only walk onto cells where grid is -1, and I make them -2.
And so on.
*/

class Solution {
    const int empty = 0;
    const int building = 1;
    const int obstacle = 2;
    const vector<int> next{ 0, 1, 0, -1, 0 };
public:
    int shortestDistance(vector<vector<int>>& grid) {
        auto m = grid.size(), n = grid.front().size();
        auto idx = 0, mindist = INT_MAX;
        auto dists = grid;
        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                if (grid[i][j] != building)
                    continue;
                mindist = INT_MAX;
                queue<tuple<int, int, int>> frontier;
                frontier.emplace(i, j, 0);
                while (!frontier.empty()) {
                    auto f_i = get<0>(frontier.front());
                    auto f_j = get<1>(frontier.front());
                    auto f_d = get<2>(frontier.front());
                    frontier.pop();
                    for (auto step = 0; step < 4; step++) {
                        auto n_i = f_i + next[step];
                        auto n_j = f_j + next[step + 1];
                        if (n_i >= 0 && n_i < m && n_j >= 0 && n_j < n && grid[n_i][n_j] == idx) {
                            frontier.emplace(n_i, n_j, f_d + 1);
                            mindist = min(dists[n_i][n_j] += f_d + 1, mindist);
                            grid[n_i][n_j]--;
                        }
                    }
                }
                idx--;
                if (mindist == INT_MAX)
                    return -1;
            }
        }
        return mindist;
    }
};

int main(void) {
    return 0;
}