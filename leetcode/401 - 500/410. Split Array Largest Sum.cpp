#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long long>> dp(m, vector<long long>(n));
        dp[0][0] = nums[0];
        for (auto i = 1; i < n; i++)
            dp[0][i] = dp[0][i - 1] + nums[i];

        for (auto i = 1; i < m; i++) {
            for (int j = i; j < n; j++) {
                int left = i - 1, right = j - 1;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (dp[0][j] - dp[0][mid] >= dp[i - 1][mid])
                        left = mid + 1;
                    else
                        right = mid;
                }
                auto res = max(dp[0][j] - dp[0][left], dp[i - 1][left]);
                if (left - 1 >= i - 1)
                    res = min(res, max(dp[0][j] - dp[0][left - 1], dp[i - 1][left - 1]));
                dp[i][j] = res;
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(void) {
    return 0;
}
