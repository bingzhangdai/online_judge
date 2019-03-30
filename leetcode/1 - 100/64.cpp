#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto dp = vector<vector<int>>(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        int i = 1, j = 1;
        while (i < m || j < n) {
            if (j < n) {
                dp[0][j] = dp[0][j-1] + grid[0][j];
                for (int ii = 1; ii < i; ii++) {
                    dp[ii][j] = min(dp[ii][j-1], dp[ii-1][j]) + grid[ii][j];
                }
            }
            if (i < m) {
                dp[i][0] = dp[i-1][0] + grid[i][0];
                for (int jj = 1; jj < j; jj++) {
                    dp[i][jj] = min(dp[i-1][jj], dp[i][jj-1]) + grid[i][jj];
                }
            }
            if (i < m && j < n) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
            if (i < m) i++;
            if (j < n) j++;
        }
        return dp[m-1][n-1];
    }
};

int main(void) {
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << Solution().minPathSum(grid) << endl;
    // system("pause");
    return 0;
}
