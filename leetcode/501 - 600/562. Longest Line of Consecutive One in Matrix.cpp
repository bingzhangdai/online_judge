#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int m = 0;
    int n = 0;
    bool hor(const vector<vector<int>>& M, int i, int j) {
        return M[i][j] == 1 && (j == 0 || M[i][j - 1] == 0);
    }
    bool ver(const vector<vector<int>>& M, int i, int j) {
        return M[i][j] == 1 && (i == 0 || M[i - 1][j] == 0);
    }
    bool diag(const vector<vector<int>>& M, int i, int j) {
        return M[i][j] == 1 && (i == 0 || j == 0 || M[i - 1][j - 1] == 0);
    }
    bool anti_diag(const vector<vector<int>>& M, int i, int j) {
        return M[i][j] == 1 && (i == 0 || j == n - 1 || M[i - 1][j + 1] == 0);
    }
    int cal_hor(const vector<vector<int>>& M, int i, int j) {
        int res = 0;
        while (j < n && M[i][j] == 1)
            res++, j++;
        return res;
    }
    int cal_ver(const vector<vector<int>>& M, int i, int j) {
        int res = 0;
        while (i < m && M[i][j] == 1)
            res++, i++;
        return res;
    }
    int cal_diag(const vector<vector<int>>& M, int i, int j) {
        int res = 0;
        while (i < m && j < n && M[i][j] == 1)
            res++, i++, j++;
        return res;
    }
    int cal_anti_diag(const vector<vector<int>>& M, int i, int j) {
        int res = 0;
        while (i < m && j >= 0 && M[i][j] == 1)
            res++, i++, j--;
        return res;
    }
public:
    int longestLine(vector<vector<int>>& M) {
        auto res = 0;
        m = M.size();
        if (m == 0) return 0;
        n = M.front().size();
        if (n == 0) return 0;
        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                if (hor(M, i, j))
                    res = max(res, cal_hor(M, i, j));
                if (ver(M, i, j))
                    res = max(res, cal_ver(M, i, j));
                if (diag(M, i, j))
                    res = max(res, cal_diag(M, i, j));
                if (anti_diag(M, i, j))
                    res = max(res, cal_anti_diag(M, i, j));
            }
        }
        return res;
    }
};

int main(void) {
    return 0;
}
