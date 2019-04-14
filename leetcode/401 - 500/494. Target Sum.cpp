#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Another solution
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (S > sum || S < - sum)
            return 0;
        sum += S;
        if (sum & 1)
            return 0;
        sum /= 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (auto num : nums) {
            for (int target = sum; target >= num; target--) {
                dp[target] += dp[target - num];
            }
        }
        return dp[sum];
    }
};

/*
class Solution {
    int res = 0;
    void dfs(const vector<int>& nums, int curr, int index, int S) {
        if (index == nums.size()) {
            if (curr == S)
                res++;
            return;
        }
        dfs(nums, curr + nums[index], index + 1, S);
        dfs(nums, curr - nums[index], index + 1, S);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        dfs(nums, 0, 0, S);
        return res;
    }
};
*/

int main(void) {
    return 0;
}
