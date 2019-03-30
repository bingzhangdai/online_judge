#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        auto grid = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        grid[0][0] = 1;
        int i = 1, j = 1;
        while (i < m || j < n) {
            if (j < n) {
                grid[0][j] = grid[0][j-1];
                for (int ii = 1; ii < i; ii++) {
                    grid[ii][j] = grid[ii][j-1] + grid[ii-1][j];
                }
            }
            if (i < m) {
                grid[i][0] = grid[i-1][0];
                for (int jj = 1; jj < j; jj++) {
                    grid[i][jj] = grid[i-1][jj] + grid[i][jj-1];
                }
            }
            if (i < m && j < n)
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            if (i < m) i++;
            if (j < n) j++;
        }
        return grid[m-1][n-1];
    }
};

int main(void) {
    cout << Solution().uniquePaths(8, 6) << endl;
    // system("pause");
    return 0;
}
