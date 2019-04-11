#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int>> frontier;
        int dist = 0, m = matrix.size(), n = matrix.front().size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    res[i][j] = 0;
                    frontier.emplace(i, j);
                }
            }
        }
        while (!frontier.empty()) {
            auto& curr = frontier.front();
            int i = curr.first, j = curr.second;
            if (i > 0) {
                if (res[i - 1][j] == INT_MAX)
                    frontier.emplace(i - 1, j);
                res[i - 1][j] = min(res[i - 1][j], res[i][j] + 1);
            }
            if (j > 0) {
                if (res[i][j - 1] == INT_MAX)
                    frontier.emplace(i, j - 1);
                res[i][j - 1] = min(res[i][j - 1], res[i][j] + 1);
            }
            if (i + 1 < matrix.size()) {
                if (res[i + 1][j] == INT_MAX)
                    frontier.emplace(i + 1, j);
                res[i + 1][j] = min(res[i + 1][j], res[i][j] + 1);
            }
            if (j + 1 < matrix.front().size()) {
                if (res[i][j + 1] == INT_MAX)
                    frontier.emplace(i, j + 1);
                res[i][j + 1] = min(res[i][j + 1], res[i][j] + 1);
            }
            frontier.pop();
        }
        return res;
    }
};

int main(void) {
    return 0;
}
