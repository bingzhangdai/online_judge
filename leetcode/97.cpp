#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size() + 1, n = s2.size() + 1;
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            dp[i][0] = s1.substr(0, i) == s3.substr(0, i);
        for (int j = 0; j < n; j++)
            dp[0][j] = s2.substr(0, j) == s3.substr(0, j);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (s1[i-1] == s3[i+j-1])
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                if (s2[j-1] == s3[i+j-1])
                    dp[i][j] = dp[i][j] || dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(void) {
    cout << Solution().isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    // system("pause");
    return 0;
}
