#include <iostream>
#include <vector>
using namespace std;

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target) {
                    return { i, j };
                }
    }
};

int main(void) {
    Solution s = Solution();
    vector<int> nums = { 2, 7, 11, 15 };
    auto res = s.twoSum(nums, 9);
    cout << res[0] << " " << res[1] << endl;

    return 0;
}
