#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row(false), col(false);
        for_each(matrix[0].begin(), matrix[0].end(), [&row](int x) {
            if (x == 0)
                row = true;
        });
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                col = true;
                break;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
            }
        }
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++)
                    matrix[i][j] = 0;
            }
        }
        if (row) {
            for (auto& x : matrix[0])
                x = 0;
        }
        if (col) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main(void) {
    vector<vector<int>> matrix {{1,2,3}, {4,0,6}, {7,8,9}};
    Solution().setZeroes(matrix);
    // system("pause");
    return 0;
}
