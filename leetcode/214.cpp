#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
// I have not expected that O(n**2) DP alg. will be TLE
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0)
            return s;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int len = 1; len <= n; len++)
            for (int i = 0; i + len - 1 < n; i++) {
                dp[i][i + len - 1] = s[i] == s[i + len - 1];
                if (len >= 3)
                    dp[i][i + len - 1] = dp[i][i + len - 1] && dp[i + 1][i + len - 2];
            }
        if (dp[0][n - 1])
            return s;
        for (int i = n - 1; i >= 0; i--)
            if (dp[0][i]) {
                auto adding = s.substr(i + 1, n - i - 1);
                reverse(adding.begin(), adding.end());
                return adding + s;
            }
        return s;
    }
};
*/

// KMP
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s == "")
            return s;
        auto s2 = s;
        reverse(s2.begin(), s2.end());
        auto tmps = s + " " + s2;
        int n = tmps.size();
        vector<int> next(n + 1, 0);
        for (int j = 0, i = 1; i < n; i++) {
            while (j && tmps[i] != tmps[j])
                j = next[j];
            if (tmps[i] == tmps[j])
                next[i+1] = ++j;
        }
        auto adding = s.substr(next[n]);
        reverse(adding.begin(), adding.end());
        return adding + s;
    }
};

int main(void) {
    cout << Solution().shortestPalindrome("aabba") << endl;
    return 0;
}
