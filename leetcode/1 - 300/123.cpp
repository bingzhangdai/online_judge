#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, n = prices.size(), min_price, max_price;
        vector<int> pre_profit(n, 0), post_profit(n, 0);
        // scan from left to right
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                min_price = prices[i];
                continue;
            }
            if (prices[i] < min_price)
                min_price = prices[i];
            pre_profit[i] = max(prices[i] - min_price, pre_profit[i-1]);
        }
        // scan from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                max_price = prices[i];
                continue;
            }
            if (prices[i] > max_price)
                max_price = prices[i];
            post_profit[i] = max(max_price - prices[i], post_profit[i+1]);
        }
        for (int i = 0; i <= n; i++) {
            int profit = 0;
            if (i != 0)
                profit += pre_profit[i-1];
            if (i != n)
                profit += post_profit[i];
            if (profit > max_profit)
                max_profit = profit;
        }
        return max_profit;
    }
};
int main(void) {
    vector<int> prices {3, 2, 6, 5, 0, 3};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}
