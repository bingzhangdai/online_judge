#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), pre_val, prepre_val;
        if (n < 2)
            return n == 0 ? 0 : nums[0];
        prepre_val = nums[0];
        pre_val = max(prepre_val, nums[1]);
        for (int i = 2; i < n; i++) {
            int val = max(prepre_val + nums[i], pre_val);
            prepre_val = pre_val;
            pre_val = val;
        }
        return pre_val;
    }
};

int main(void) {
    return 0;
}
