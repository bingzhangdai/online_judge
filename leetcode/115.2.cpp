#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        auto m(s.length()), n(t.length());
        if (n > m)
            return 0;
        auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (auto i = 0; i <= m ; i++) {
            dp[i][0] = 1;
        }
        for (auto i = 1; i <= m; i++) {
            for (auto j = 1; j <= i && j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};

int main(void) {
    cout << Solution().numDistinct("ccc", "c") << endl;
    return 0;
}
