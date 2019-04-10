#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<vector<int>> increasing_path;
    int m, n;
    int dfs(const vector<vector<int>>& matrix, int i, int j) {
        if (increasing_path[i][j] != 0)
            return increasing_path[i][j];
        int path = 0;
        if (i > 0 && matrix[i - 1][j] > matrix[i][j])
            path = max(dfs(matrix, i - 1, j), path);
        if (j > 0 && matrix[i][j - 1] > matrix[i][j])
            path = max(dfs(matrix, i, j - 1), path);
        if (i < m - 1 && matrix[i + 1][j] > matrix[i][j])
            path = max(dfs(matrix, i + 1, j), path);
        if (j < n - 1 && matrix[i][j + 1] > matrix[i][j])
            path = max(dfs(matrix, i, j + 1), path);
        return increasing_path[i][j] = path + 1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (m == 0) return 0;
        n = matrix[0].size();
        if (n == 0) return 0;
        increasing_path.resize(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                res = max(dfs(matrix, i, j), res);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
