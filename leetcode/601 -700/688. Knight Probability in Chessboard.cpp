#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
    const vector<vector<int>> dir {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp(N, vector<double>(N)), tmp(N, vector<double>(N));
        dp[r][c] = 1;
        while (K--) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    tmp[i][j] = 0;
                    for (const auto& d : dir) {
                        r = i + d[0], c = j + d[1];
                        if (r >= 0 && r < N && c >= 0 && c < N)
                            tmp[i][j] += dp[r][c] / dir.size();
                    }
                }
            }
            swap(dp, tmp);
        }
        return accumulate(dp.begin(), dp.end(), 0.0, [](double i, const vector<double>& r) {
            return i + accumulate(r.begin(), r.end(), 0.0);
        });
    }
};

int main(void) {
    return 0;
}
