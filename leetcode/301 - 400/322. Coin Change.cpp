#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (auto i = 1; i <= amount; i++) {
            auto num = INT_MAX;
            for (auto c : coins) {
                if (i - c >= 0 && dp[i - c] != -1 && dp[i - c] + 1 < num)
                    num = dp[i - c] + 1;
            }
            if (num != INT_MAX)
                dp[i] = num;
        }
        return dp.back();
    }
};

int main(void) {
    return 0;
}
