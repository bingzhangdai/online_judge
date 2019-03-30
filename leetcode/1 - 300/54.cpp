#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0)
            return res;
        int m(matrix.size()), n(matrix[0].size()), i, j;
        for (i = j = 0; j < m && j < n; i++, j++, n--, m--) {
            for (int x = j; x < n; x++)
                res.push_back(matrix[i][x]);
            for (int x = i + 1; x < m; x++)
                res.push_back(matrix[x][n - 1]);
            for (int x = n - 2; m - 1 != i && x >= j; x--)
                res.push_back(matrix[m - 1][x]);
            for (int x = m - 2; n - 1 != j && x > i; x--)
                res.push_back(matrix[x][j]);
        }
        return res;
    }
};

int main(void) {
    vector<vector<int>> nums = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    cout << Solution().spiralOrder(nums).size() << endl;
    // system("pause");
    return 0;
}
