#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class NumMatrix {
    int m, n;
    vector<vector<int>> left_corner = vector<vector<int>>(0, vector<int>(0, 0));
    vector<vector<int>> right_corner = vector<vector<int>>(0, vector<int>(0, 0));
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (!m) return;
        n = matrix[0].size();
        if (!n) return;
        left_corner.resize(m, vector<int>(n, 0));
        right_corner.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i > 0)
                    left_corner[i][j] += left_corner[i - 1][j];
                if (j > 0)
                    left_corner[i][j] += left_corner[i][j - 1];
                if (i > 0 && j > 0)
                    left_corner[i][j] -= left_corner[i - 1][j - 1];
                left_corner[i][j] += matrix[i][j];
            }
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--) {
                if (i < m - 1)
                    right_corner[i][j] += right_corner[i + 1][j];
                if (j < n - 1)
                    right_corner[i][j] += right_corner[i][j + 1];
                if (i < m - 1 && j < n - 1)
                    right_corner[i][j] -= right_corner[i + 1][j + 1];
                right_corner[i][j] += matrix[i][j];
            }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = left_corner[row2][col2] + right_corner[row1][col1];
        if (row1 > 0)
            res -= left_corner[row1 - 1][col2];
        if (col1 > 0)
            res -= left_corner[row2][col1 - 1];
        if (row1 > 0 && col1 > 0)
            res += left_corner[row1 - 1][col1 - 1];
        if (row2 < m - 1)
            res -= right_corner[row2 + 1][col1];
        if (col2 < n - 1)
            res -= right_corner[row1][col2 + 1];
        if (row2 < m - 1 && col2 < n - 1)
            res += right_corner[row2 + 1][col2 + 1];
        return res / 2;
    }
};

int main(void) {
    return 0;
}
