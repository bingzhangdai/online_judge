#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        auto n = matrix.size();
        auto I = (n + 1) / 2, J = n / 2;
        for (auto i = 0; i < I; i++) {
            for (auto j = 0; j < J; j++) {
                auto tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j][i];
                matrix[n - j][i] = matrix[n - i][n - j];
                matrix[n - i][n - j] = matrix[j][n - i];
                matrix[j][n - i] = tmp;
            }
        }
    }
};

int main(void) {
    vector<vector<int>> nums = { {1,2,3}, {4,5,6}, {7,8,9} };
    Solution().rotate(nums);
    // system("pause");
    return 0;
}
