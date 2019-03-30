#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        if (days == 0) return 0;
        int sell_before_yesterday = 0, sell_yesterday = 0;
        int buy_yesterday = -prices[0];
        for (int i = 1; i < days; i++) {
            int sell = max(prices[i] + buy_yesterday, sell_yesterday);
            buy_yesterday = max(buy_yesterday, sell_before_yesterday - prices[i]);
            sell_before_yesterday = sell_yesterday;
            sell_yesterday = sell;
        }
        return sell_yesterday;
    }
};

int main(void) {
    return 0;
}
