#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        vector<int> dp(n, 0);
        vector<int> path(n, 0);
        for (int i = 0; i < n; i++) {
            int max_subset = -1;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (max_subset == -1 || dp[max_subset] < dp[j])
                        max_subset = j;
                }
            }
            path[i] = max_subset;
            dp[i] = max_subset == -1 ? 1 : (dp[max_subset] + 1);
        }
        int i = max_element(dp.begin(), dp.end()) - dp.begin();
        vector<int> res;
        do {
            res.push_back(nums[i]);
        }
        while ((i = path[i]) != -1);
        return res;
    }
};

int main(void) {
    return 0;
}
