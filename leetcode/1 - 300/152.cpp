#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
// dp, O(n**2), TLE
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = dp[i][j-1] * nums[j];
                if (dp[i][j] > max_product)
                    max_product = dp[i][j];
            }
        }
        return max_product;
    }
};
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_max(n), dp_min(n);
        dp_max[0] = dp_min[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp_max[i] = max({ nums[i], nums[i]*dp_max[i-1], nums[i]*dp_min[i-1] });
            dp_min[i] = min({ nums[i], nums[i]*dp_max[i-1], nums[i]*dp_min[i-1] });
        }
        return *max_element(dp_max.begin(), dp_max.end());
    }
};

int main(void) {
    vector<int> nums {2, 3, -2, 4};
    cout << Solution().maxProduct(nums) << endl;
    return 0;
}
