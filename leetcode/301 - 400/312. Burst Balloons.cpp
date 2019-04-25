#include <iostream>
#include <climits>
#include <vector>
using namespace std;

/*
Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i < n; i++) {
                int j = i + len - 1;
                if (j >= n)
                    break;
                for (int k = i; k <= j; k++) {
                    int coins = nums[k] * (i > 0 ? nums[i - 1] : 1) * (j + 1 < n ? nums[j + 1] : 1);
                    if (k - 1 >= i)
                        coins += dp[i][k - 1];
                    if (k + 1 <= j)
                        coins += dp[k + 1][j];
                    dp[i][j] = max(dp[i][j], coins);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main(void) {
    return 0;
}
