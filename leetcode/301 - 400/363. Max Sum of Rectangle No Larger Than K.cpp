#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2 
Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
             and 2 is the max number no larger than k (k = 2).
*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        vector<vector<int>> sums(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sums[i][j] = matrix[i][j];
                if (j > 0) sums[i][j] += sums[i][j - 1];
                if (i > 0) sums[i][j] += sums[i - 1][j];
                if (i > 0 && j > 0) sums[i][j] -= sums[i - 1][j - 1];
            }
        }
        int max_sum = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int t = 0; t <= i; t++) {
                    for (int l = 0; l <= j; l++) {
                        int curr_sum = sums[i][j];
                        if (t > 0) curr_sum -= sums[t - 1][j];
                        if (l > 0) curr_sum -= sums[i][l - 1];
                        if (t > 0 && l > 0) curr_sum += sums[t - 1][l - 1];
                        if (curr_sum > max_sum && curr_sum <= k) max_sum = curr_sum;
                    }
                }
            }
        }
        return max_sum;
    }
};

int main(void) {
    vector<vector<int>> matrix {{1, 0, 1}, {0, -2, 3}};
    Solution().maxSumSubmatrix(matrix, 2);
    return 0;
}
