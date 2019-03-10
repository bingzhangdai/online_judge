#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Put nums[i] at position nums[i] - 1
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == i + 1)
                continue;
            auto tmp = nums[i];
            do {
                auto t = nums[tmp - 1];
                nums[tmp - 1] = tmp;
                tmp = t;
            } while (tmp > 0 && tmp <= nums.size() && tmp != nums[tmp - 1]);
        }
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }
};

int main(void) {
    vector<int> nums = { 1, 2, 0 };
    cout << Solution().firstMissingPositive(nums) << endl;
    return 0;
}
