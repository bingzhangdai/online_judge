#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = key.length(), n = ring.length();
        vector<vector<int>> dp(m + 1, vector<int>(n, INT_MAX));
        dp[0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (ring[j] != key[i])
                    continue;
                for (int k = 0; k < n; k++) {
                    if (dp[i][k] == INT_MAX)
                        continue;
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + min({ abs(j - k), j + n - k, k + n - j }) + 1);
                }
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};

// LTE
/*
class Solution {
    int res = INT_MAX;

    void dfs(const string& ring, int pos, const string& key, int i, int steps) {
        if (i == key.length()) {
            res = min(res, steps);
            return;
        }
        int n = ring.length();
        for (int j = 0; j <= n / 2; j++) {
            int pos_new = (j + pos) % n;
            if (ring[pos_new] != key[i])
                continue;
            dfs(ring, pos_new, key, i + 1, steps + min(abs(pos_new - pos),  pos_new + n - pos) + 1);
            break;
        }
        for (int j = 0; j <= n / 2; j++) {
            int pos_new = (pos - j + n) % n;
            if (ring[pos_new] != key[i])
                continue;
            dfs(ring, pos_new, key, i + 1, steps + min(abs(pos_new - pos), pos + n - pos_new) + 1);
            break;
        }
    }

public:
    int findRotateSteps(string ring, string key) {
        dfs(ring, 0, key, 0, 0);
        return res;
    }
};
*/

int main(void) {
    return 0;
}
