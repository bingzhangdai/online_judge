#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DFS will be LTE
/*
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        int res = 0;
        for (auto num : nums)
            res += combinationSum4(nums, target - num);
        return res;
    }
};
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long> count(target + 1, 0);
        count[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i >= num)
                    count[i] += count[i - num];
                if (count[i] > INT_MAX)
                    count[i] = INT_MAX;
            }
        }
        return count.back();
    }
};

int main(void) {
    return 0;
}
