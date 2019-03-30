#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto m(s1.length()), n(s2.length());
        if (m + n != s3.length())
            return false;
        auto dp = vector<vector<bool>>(m + 1, vector<bool>(n + 1, true));
        for (auto i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }
        for (auto j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }
        for (auto i = 1; i <= m; i++) {
            for (auto j = 1; j <= n; j++) {
                dp[i][j] = (s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j]
                    || (s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

int main(void) {
    cout << Solution().isInterleave("aacaac", "aacaaeaac", "aacaaeaaeaacaac") << endl;
    // system("pause");
    return 0;
}
