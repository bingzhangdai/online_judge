#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution_LCS {
    string LCS(const string& str1, const string& str2) {
        auto n = str1.length() + 1, m = str2.length() + 1;
        vector<string> dp(m), tmp(m);
        for (auto i = 1; i < n; i++) {
            for (auto j = 1; j < m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    tmp[j] = dp[j - 1] + str1[i - 1];
                } else if (dp[j].length() < tmp[j - 1].length()) {
                    tmp[j] = tmp[j - 1];
                } else {
                    tmp[j] = dp[j];
                }
            }
            swap(dp, tmp);
        }
        return dp.back();
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string res = "";
        auto i = 0, j = 0;
        for (auto c : LCS(str1, str2)) {
            while (str1[i] != c)
                res += str1[i++];
            while (str2[j] != c)
                res += str2[j++];
            res += c, i++, j++;
        }
        if (i < str1.length())
            res += str1.substr(i);
        if (j < str2.length())
            res += str2.substr(j);
        return res;
    }
};

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        auto n = str1.length() + 1, m = str2.length() + 1;
        vector<string> dp(m), tmp(m);
        for (auto j = 1; j < m; j++) {
            dp[j] = str2.substr(0, j);
        }
        for (auto i = 1; i < n; i++) {
            tmp[0] = str1.substr(0, i);
            for (auto j = 1; j < m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    tmp[j] = dp[j - 1] + str1[i - 1];
                } else if (dp[j].length() < tmp[j - 1].length()) {
                    tmp[j] = dp[j] + str1[i - 1];
                } else {
                    tmp[j] = tmp[j - 1] + str2[j - 1];
                }
            }
            swap(dp, tmp);
        }
        return dp.back();
    }
};

// Memory Limit Exceeded
class Solution_MLE {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        auto n = str1.length() + 1, m = str2.length() + 1;
        vector<vector<string>> dp(n, vector<string>(m));
        for (auto i = 0; i < n; i++) {
            dp[i][0] = str1.substr(0, i);
        }
        for (auto j = 0; j < m; j++) {
            dp[0][j] = str2.substr(0, j);
        }
        for (auto i = 1; i < n; i++) {
            for (auto j = 1; j < m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + str1[i - 1];
                } else if (dp[i - 1][j].length() < dp[i][j - 1].length()) {
                    dp[i][j] = dp[i - 1][j] + str1[i - 1];
                } else {
                    dp[i][j] = dp[i][j - 1] + str2[j - 1];
                }
            }
        }
        return dp.back().back();
    }
};

int main(void) {
    return 0;
}
