#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// wrong dp
/*
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(2, INT_MAX));
        dp[1][0] = 0;
        dp[1][1] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                int tmp_money = 0, tmp_move = 0;
                if (j - 1 >= 1) {
                    tmp_money = max(dp[j - 1][0], tmp_money);
                    tmp_move = max(dp[j - 1][1], tmp_move);
                }
                if (i - j >= 1) {
                    tmp_money = max(dp[i - j][0] + dp[i - j][1] * j, tmp_money);
                    tmp_move = max(dp[i - j][1], tmp_move);
                }
                if (i == 6)
                    cout << tmp_move << endl;
                dp[i][0] = min(dp[i][0], j + tmp_money);
                dp[i][1] = min(dp[i][1], 1 + tmp_move);
            }
        }
        return dp[n][0];
    }
};
*/

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int j = 2; j <= n; j++) {
            for (int i = 1; j + i - 1  <= n; i++) {
                int right = j + i - 1;
                dp[i][right] = INT_MAX;
                for (int k = i; k <= right; k++) {
                    int local = 0;
                    if (i <= k - 1 && dp[i][k - 1] > local)
                        local = dp[i][k - 1];
                    if (k + 1 <= right && dp[k + 1][right] > local)
                        local = dp[k + 1][right];
                    local += k;
                    dp[i][right] = min(local, dp[i][right]);
                }
            }
        }
        return dp[1][n];
    }
};

int main(void) {
    Solution().getMoneyAmount(3);
    return 0;
}
