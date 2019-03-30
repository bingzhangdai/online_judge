#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size() + 1, n = t.size() + 1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 1; j < n; j++) {
            for (int i = j; i < m; i++) {
                if (s[i-1] == t[j-1])
                    dp[i][j] += dp[i-1][j-1];
                dp[i][j] += dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(void) {
    cout << Solution().numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}
