#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, min_price = INT_MAX;
        for (auto i = 0; i < prices.size(); i++) {
            profit = max(prices[i] - min_price, profit);
            min_price = min(min_price, prices[i]);
        }
        return profit;
    }
};

int main(void) {
    return 0;
}
