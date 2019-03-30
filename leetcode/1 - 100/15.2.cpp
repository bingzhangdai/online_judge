#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.
Example:
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        auto res = vector<vector<int>>();
        sort(nums.begin(), nums.end());
        for (auto i = 0; i < nums.size();) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                auto sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                }
                if (sum <= 0) {
                    int tmp = j + 1;
                    while (tmp < k && nums[tmp] == nums[j]) { tmp++; }
                    j = tmp;
                }
                else {
                    int tmp = k - 1;
                    while (tmp > j && nums[tmp] == nums[k]) { tmp--; }
                    k = tmp;
                }
            }
            int tmp = i + 1;
            while (tmp < nums.size() && nums[tmp] == nums[i]) { tmp++; }
            i = tmp;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
