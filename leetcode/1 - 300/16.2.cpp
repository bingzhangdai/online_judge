#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
Example:
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0, diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (auto i = 0; i < nums.size();) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                auto sums = nums[i] + nums[j] + nums[k];
                if (abs(sums - target) < diff) {
                    res = sums;
                    diff = abs(sums - target);
                }
                if (sums - target <= 0) {
                    auto tmp = j + 1;
                    while (tmp < k && nums[tmp] == nums[j]) { tmp++; }
                    j = tmp;
                }
                else {
                    auto tmp = k - 1;
                    while (tmp > j && nums[tmp] == nums[k]) { tmp--; }
                    k = tmp;
                }
            }
            auto tmp = i + 1;
                while (tmp < nums.size() && nums[tmp] == nums[i]) { tmp++; }
            i = tmp;
        }
        return res;
    }
};

int main(void) {
    vector<int> test_case = { -1, 2, 1, -4 };
    cout << Solution().threeSumClosest(test_case, 1) << endl;

    return 0;
}
