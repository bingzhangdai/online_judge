#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
You have the following 3 operations permitted on a word:
Insert a character
Delete a character
Replace a character
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (auto i = 0; i < m + 1; i++) {
            for (auto j = 0; j < n + 1; j++) {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else
                    dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1)});
            }
        }
        return dp[m][n];
    }
};

int main(void) {
    cout << Solution().minDistance("word1", "word2") << endl;
    // system("pause");
    return 0;
}
