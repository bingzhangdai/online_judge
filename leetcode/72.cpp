#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

/*
a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m(word1.size() + 1), n(word2.size() + 1);
        auto dp = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            dp[i][0] = i;
        for (int j = 0; j < n; j++)
            dp[0][j] = j;
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = min({dp[i][j-1] + 1, dp[i-1][j] + 1, (word1[i-1] == word2[j-1]) ? dp[i-1][j-1] : dp[i-1][j-1] + 1});
        return dp[m-1][n-1];
    }
};

int main(void) {
    cout << Solution().minDistance("word1", "word2") << endl;
    // system("pause");
    return 0;
}
