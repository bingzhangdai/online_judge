#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        auto grid = vector<vector<int>>(m, vector<int>(n, 0));
        grid[0][0] = 1;
        int i = 1, j = 1;
        while (i < m || j < n) {
            if (j < n) {
                if (obstacleGrid[0][j-1] == 0)
                    grid[0][j] = grid[0][j-1];
                for (int ii = 1; ii < i; ii++) {
                    if (obstacleGrid[ii][j-1] == 0)
                        grid[ii][j] += grid[ii][j-1];
                    if (obstacleGrid[ii-1][j] == 0)
                        grid[ii][j] += grid[ii-1][j];
                }
            }
            if (i < m) {
                if (obstacleGrid[i-1][0] == 0)
                    grid[i][0] = grid[i-1][0];
                for (int jj = 1; jj < j; jj++) {
                    if (obstacleGrid[i-1][jj] == 0)
                        grid[i][jj] += grid[i-1][jj];
                    if (obstacleGrid[i][jj-1] == 0)
                        grid[i][jj] += grid[i][jj-1];
                }
            }
            if (i < m && j < n) {
                if (obstacleGrid[i-1][j] == 0)
                    grid[i][j] += grid[i-1][j];
                if (obstacleGrid[i][j-1] == 0)
                    grid[i][j] += grid[i][j-1];
            }
            if (i < m) i++;
            if (j < n) j++;
        }
        return (obstacleGrid[m-1][n-1] == 0) ? grid[m-1][n-1] : 0;
    }
};

int main(void) {
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << Solution().uniquePathsWithObstacles(obstacleGrid) << endl;
    // system("pause");
    return 0;
}
