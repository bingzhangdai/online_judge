#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.

Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).
*/

class Solution {
    const int num_arrays = 3;
public:
    vector<int> maxSumOfThreeSubarrays(const vector<int>& nums, int k) {
        int n = nums.size() - k + 1;
        vector<int> sums(n, 0);
        // range 0 ~ k - 1
        sums[0] = accumulate(nums.begin(), nums.begin() + k, 0);
        for (int i = 1; i < n; i++) {
            sums[i] = sums[i - 1] + nums[i + k - 1] - nums[i - 1];
        }
        vector<vector<int>> dp(num_arrays, vector<int>(n, 0));
        dp[0][0] = sums[0];
        for (int j = 1; j < n; j++) {
            dp[0][j] = max(sums[j], dp[0][j - 1]);
        }
        for (int i = 1; i < num_arrays; i++) {
            for (int j = i * k; j < n; j++) {
                dp[i][j] = max(sums[j] + dp[i - 1][j - k], dp[i][j - 1]);
            }
        }
        vector<int> res(num_arrays);
        int len = n;
        for (int i = num_arrays - 1; i>= 0; i--) {
            res[i] = max_element(dp[i].begin(), dp[i].begin() + len) - dp[i].begin();
            len = res[i] - k + 1;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
