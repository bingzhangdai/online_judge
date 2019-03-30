#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        auto dp = vector<vector<int>>(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (auto i = 0; i < m; i++)
            dp[i][0] = 1;
        for (auto j = 0; j < n; j++)
            dp[0][j] = 1;
        for (auto i = 1; i < m; i++) {
            for (auto j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(void) {
    cout << Solution().uniquePaths(7, 3) << endl;
    return 0;
}
