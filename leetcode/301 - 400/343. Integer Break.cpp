#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Example 1:
Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:
Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 3; i <= n; i++) {
            int tmp = 0;
            for (int j = 1; j < i - 1; j++)
                tmp = max({ tmp, j * dp[i - j], j * (i - j) });
            dp[i] = tmp;
        }
        return dp[n];
    }
};

int main(void) {
    return 0;
}
