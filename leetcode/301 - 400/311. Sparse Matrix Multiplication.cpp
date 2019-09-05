#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        auto m = A.size(), k = A.front().size(), n = B.front().size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (auto i = 0; i < m; i++) {
            for (auto p = 0; p < k; p++) {
                if (!A[i][p])
                    continue;
                for (auto j = 0; j < n; j++) {
                    res[i][j] += A[i][p] * B[p][j];
                }
            }
        }
        return res;
    }
};

class Solution_Brute_Force {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        auto m = A.size(), k = A.front().size(), n = B.front().size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                for (auto p = 0; p < k; p++) {
                    res[i][j] += A[i][p] * B[p][j];
                }
            }
        }
        return res;
    }
};

int main(void) {
    return 0;
}
