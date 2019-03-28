#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        auto days = prices.size();
        auto dp = vector<vector<int>>(k, vector<int>(days, 0));
        // at most i + 1 transactions, for the first j days.
        int max_profit = 0;
        for (auto i = 0; i < k; i++) {
            // last day can either sell or do nothing
            for (auto j = 0; j < days; j++) {
                int max_profit_if_sell = 0;
                for (auto k = 0; k < j; k++) {
                    max_profit_if_sell = max((i == 0 ? 0 : dp[i - 1][k]) + prices[j] - prices[k], max_profit_if_sell);
                }
                dp[i][j] = max(j == 0 ? 0 : dp[i][j - 1], max_profit_if_sell);
                max_profit = max(dp[i][j], max_profit);
            }
        }
        return max_profit;
    }
};
*/
/*
// Can reduce the space used. k => 2
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        auto days = prices.size();
        auto dp = vector<vector<int>>(2, vector<int>(days, 0));
        // at most i + 1 transactions, for the first j days.
        int max_profit = 0;
        for (auto i = 0; i < k; i++) {
            auto index = (i + 1) % 2, prev_index = i % 2;
            // last day can either sell or do nothing
            for (auto j = 0; j < days; j++) {
                int max_profit_if_sell = 0;
                for (auto m = 0; m < j; m++) {
                    max_profit_if_sell = max(dp[prev_index][m] + prices[j] - prices[m], max_profit_if_sell);
                }
                dp[index][j] = max(j == 0 ? 0 : dp[index][j - 1], max_profit_if_sell);
                max_profit = max(dp[index][j], max_profit);
            }
        }
        return max_profit;
    }
};
*/
// Can be O(n^2)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        auto days = prices.size();
        if (days == 0)
            return 0;
        auto max_profit = vector<int>(days, 0);
        auto max_profit_if_buy = vector<int>(days);
        max_profit_if_buy[0] = -prices[0];
        for (auto i = 1; i < days; i++) {
            max_profit_if_buy[i] = max(max_profit_if_buy[i - 1], -prices[i]);
        }
        // at most i + 1 transactions, for the first j days.
        for (auto i = 0; i < k && i < days / 2; i++) {
            // last day can either sell or do nothing
            for (auto j = 1; j < days; j++) {
                int max_profit_if_sell = 0;
                max_profit_if_sell = prices[j] + max_profit_if_buy[j];
                max_profit[j] = max(max_profit[j - 1], max_profit_if_sell);
                max_profit_if_buy[j] = max(max_profit[j] - prices[j], max_profit_if_buy[j - 1]);
            }
        }
        return max_profit[days - 1];
    }
};

int main(void) {
    vector<int> prices {3,2,6,5,0,3};
    cout << Solution().maxProfit(2, prices) << endl;
    return 0;
}
