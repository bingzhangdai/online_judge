#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] != i + 1) {
                int n = nums[i];
                if (n > nums.size()) {
                    nums[i] = -1;
                    break;
                }
                // duplicate number n
                if (n == nums[n - 1])
                    break;
                swap(nums[i], nums[n - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }
};

int main(void) {
    vector<int> nums = { 1, 2, 0 };
    cout << Solution().firstMissingPositive(nums) << endl;
    system("pause");
    return 0;
}
