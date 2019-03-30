#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        auto dp = vector<vector<int>>(m, vector<int>(n, 0));
        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = (i - 1 >= 0 ? dp[i - 1][j] : 0)
                        + (j - 1 >= 0 ? dp[i][j - 1] : 0);
                if (obstacleGrid[i][j])
                    dp[i][j] = 0;
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(void) {
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << Solution().uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
