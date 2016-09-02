#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        if (n == 0)
            return false;
        vector<bool> dp(n, false);
        for (int i = 0; i < n; i++) {
            for (int j = i; j; j--) {
                if (dp[j-1] && wordDict.find(s.substr(j, i-j+1)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
            if (!dp[i])
                dp[i] = wordDict.find(s.substr(0, i+1)) != wordDict.end();
        }
        return dp[n-1];
    }
};

int main(void) {
    return 0;
}
