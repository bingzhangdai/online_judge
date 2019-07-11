#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.front().size();
        for (int i = 0; i < m; i++) {
            int r = i, c = 0, val = matrix[r][c];
            while (r < m && c < n)
                if (matrix[r++][c++] != val)
                    return false;
        }
        for (int j = 1; j < n; j++) {
            int r = 0, c = j, val = matrix[r][c];
            while (r < m && c < n)
                if (matrix[r++][c++] != val)
                    return false;
        }
        return true;
    }
};

int main(void) {
    return 0;
}
