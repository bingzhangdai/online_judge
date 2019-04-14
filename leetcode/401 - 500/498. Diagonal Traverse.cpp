#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix.front().empty())
            return {};
        int m = matrix.size(), n = matrix.front().size();
        for (int sum = 0; sum <= m + n - 2; sum++) {
            int row = sum & 1 ? max(sum - n + 1, 0) : min(sum, m - 1),
                col = sum - row,
                step = sum & 1 ? 1 : -1;
            row = sum - min(col, n - 1);
            while (col >= 0 && row >=0 && col < n && row < m) {
                res.push_back(matrix[row][col]);
                row += step;
                col -= step;
            }
        }
        return res;
    }
};

int main(void) {
    return 0;
}
