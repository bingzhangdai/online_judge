#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

/*
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        auto m = s.length(), n = p.length();
        auto dp = vector<vector<bool>>(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        // match s[0, i), p[0, j)
        for (auto i = 0; i <= m; i++) {
            for (auto j = 1; j <=n; j++) {
                auto match = false;
                if (p[j - 1] == '?' && i > 0)
                    match = dp[i - 1][j - 1];
                if (p[j - 1] == '*') {
                    for (auto k = 0; k <= i; k++) {
                        if (dp[k][j - 1]) {
                            match = true;
                            break;
                        }
                    }
                }
                else if (i > 0 && s[i - 1] == p[j - 1]) {
                    match = dp[i - 1][j - 1];
                }
                dp [i][j] = match;
            }
        }
        return dp[m][n];
    }
};

int main(void) {
    string s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    string p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    cout << Solution().isMatch(s, p) << endl;
    // system("pause");
    return 0;
}
