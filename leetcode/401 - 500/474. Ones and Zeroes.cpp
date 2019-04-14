#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.
*/

class Solution {
    pair<int, int> to_size(const string& s) {
        int n = 0;
        for (auto c : s)
            n += c - '0';
        return pair<int, int>(s.length() - n, c);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> sizes;
        for (const auto& s : strs)
            sizes.emplace_back(to_size(s));
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const auto& size : sizes) {
            for (int i = m; i - size.first >= 0; i--) {
                for (int j = n; j - size.second >= 0; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - size.first][j - size.second] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main(void) {
    return 0;
}
