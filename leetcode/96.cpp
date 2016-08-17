#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int res = 0;
        if (n == 0)
            return res;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                for (int k = j; k < i + j + 1; k++) {
                    if (k == j)
                        dp[i][j] +=dp[i-1][k+1];
                    else if (k == i + j)
                        dp[i][j] += dp[i-1][j];
                    else
                        dp[i][j] += dp[i+j-k-1][k+1] * dp[k-j-1][j];
                }
            }
        }
        return dp[n-1][0];
    }
};

int main(void) {
    cout << Solution().numTrees(3) << endl;
    // system("pause");
    return 0;
}
