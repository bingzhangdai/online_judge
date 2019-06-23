#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class NumMatrix {
    vector<vector<int>> matrix;
    vector<vector<int>> bit;
    int m, n;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        if (matrix.empty() || matrix.front().empty())
            return;
        m = matrix.size(), n = matrix.front().size();
        bit.resize(m + 1, vector<int>(1));
        for (int i = 1; i <= m; i++) {
            bit[i].insert(bit[i].end(), matrix[i - 1].begin(), matrix[i - 1].end());
            for (int j = 1; j <= n; j++) {
                int parent = j + (j & -j);
                if (parent <= n)
                    bit[i][parent] += bit[i][j];
            }
        }
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= m; i++) {
                int parent = i + (i & -i);
                if (parent <= m)
                    bit[parent][j] += bit[i][j];
            }
        }
    }

    void update(int row, int col, int val) {
        int diff = val - matrix[row][col];
        matrix[row][col] = val;
        for (int i = row + 1; i <= m; i += i & -i) {
            for (int j = col + 1; j <= n; j += j & -j) {
                bit[i][j] += diff;
            }
        }
    }

    int sum(int row, int col) {
        int res = 0;
        for (int i = row + 1; i > 0; i -= i & -i) {
            for (int j = col + 1; j > 0; j -= j & -j) {
                res += bit[i][j];
            }
        }
        return res;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2, col2) - sum(row1 - 1, col2) - sum(row2, col1 - 1) + sum(row1 - 1, col1 - 1);
    }
};

int main(void) {
    return 0;
}