#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int rob_198(vector<int>& nums) {
        int n = nums.size(), pre_val, prepre_val;
        prepre_val = nums[0];
        pre_val = max(prepre_val, nums[1]);
        for (int i = 2; i < n; i++) {
            int val = max(prepre_val + nums[i], pre_val);
            prepre_val = pre_val;
            pre_val = val;
        }
        return pre_val;
    }
public:
    int rob(vector<int>& nums) {
        int m = nums.size();
        if (m < 2)
            return m == 0 ? 0 : nums[0];
        int n = nums[0], res = 0;
        nums[0] = 0;
        res = max(res, rob_198(nums));
        nums[0] = n;
        nums.back() = 0;
        res = max(res, rob_198(nums));
        return res;
    }
};

int main(void) {
    return 0;
}
