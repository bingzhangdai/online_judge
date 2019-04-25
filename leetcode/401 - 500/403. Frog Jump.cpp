#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones.empty())
            return false;
        if (n == 1)
            return true;
        if (stones[1] != 1)
            return false;
        vector<unordered_set<int>> dp(n, unordered_set<int>());
        dp[1].insert({ 1, 2 });
        int max_reach = 3;
        for (int i = 2; i < n && i <= max_reach; i++) {
            for (int k = 1; k < i; k++) {
                if (dp[k].find(stones[i] - stones[k]) != dp[k].end()) {
                    dp[i].insert({ stones[i] - stones[k], stones[i] - stones[k] + 1, stones[i] - stones[k] - 1 });
                    max_reach = max(max_reach, stones[i] + stones[i] - stones[k] + 1);
                }
            }
        }
        return !dp[n - 1].empty();
    }
};

int main(void) {
    return 0;
}
