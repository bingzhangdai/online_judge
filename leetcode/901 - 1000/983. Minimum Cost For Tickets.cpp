#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        auto n = days.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        auto pos7 = 0, pos30 = 0;
        // dp[i] actually mapped to days[i - 1]
        for (auto i = 0; i < n; i++) {
            while (days[i] - days[pos7] >= 7)
                pos7++;
            while (days[i] - days[pos30] >= 30)
                pos30++;
            dp[i + 1] = min({dp[i] + costs[0], dp[pos7] + costs[1], dp[pos30] + costs[2]});
        }
        return dp.back();
    }
};

int main(void) {
    return 0;
}
