#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto dp = vector<vector<int>>(m, vector<int>(n, 0));
        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                dp[i][j] = min((i - 1 >= 0 ? dp[i - 1][j] : INT_MAX), (j - 1 >= 0 ? dp[i][j - 1] : INT_MAX)) + grid[i][j];
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(void) {
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << Solution().minPathSum(grid) << endl;
    // system("pause");
    return 0;
}
