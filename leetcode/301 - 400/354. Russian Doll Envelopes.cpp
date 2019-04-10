#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Example:
Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3 
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

class Solution {
    bool canFit(const pair<int, int>& smaller, const pair<int, int>& larger) {
        return smaller.first < larger.first && smaller.second < larger.second;
    }
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0)
            return 0;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i && envelopes[j].first < envelopes[i].first; j++)
                if (canFit(envelopes[j], envelopes[i]))
                    dp[i] = max(dp[i], dp[j] + 1);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main(void) {
    return 0;
}
