#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (!nums.size())
            return 0;
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = max((nums[i] > nums[j] ? dp[j] : 0) + 1, dp[i]);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
