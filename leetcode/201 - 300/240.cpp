#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto res = false;
        int i(0), j(0), m(matrix.size()), n(matrix[0].size());
        for (j = 0; j < n && matrix[0][j] <= target; j++);
        for (i = 0; i < m; i++) {
            while (j > 0 && matrix[i][j-1] > target)
                j--;
            if (j > 0 && matrix[i][j-1] == target)
                break;
        }
        return (i < m) && (j > 0) &&  matrix[i][j-1] == target;
    }
};


int main(void) {
    vector<vector<int>> matrix {{1,   3,  5,  7},
                                {10, 11, 16, 20},
                                {23, 30, 34, 50}};
    cout << Solution().searchMatrix(matrix, 80) << endl;
    // system("pause");
    return 0;
}
