#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1')
                    if (i == 0 || j == 0)
                        matrix[i][j] = 1;
                    else
                        matrix[i][j] = min({matrix[i-1][j], matrix[i-1][j-1], matrix[i][j-1]}) + 1;
                else
                    matrix[i][j] = 0;
                if (matrix[i][j] > res)
                    res = matrix[i][j];
            }
        return res * res;
    }
};

int main(void) {
    return 0;
}
