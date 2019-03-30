#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int val = INT_MAX;
            for (auto coin : coins) {
                if (i < coin)
                    continue;
                if (dp[i - coin] != -1) {
                    val = min(val, dp[i - coin] + 1);
                }
            }
            if (val != INT_MAX)
                dp[i] = val;
        }
        return dp[amount];
    }
};

int main(void) {
    return 0;
}
