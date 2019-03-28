#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> nums, dp(n + 1, INT_MAX);
        for (int i = 1; i * i <= n; i++)
            nums.push_back(i * i);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (auto j : nums) {
                if (i >= j) {
                    dp[i] = min(dp[i - j] + 1, dp[i]);
                }
            }
        }
        return dp[n];
    }
};

int main(void) {
    return 0;
}
