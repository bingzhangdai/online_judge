#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            auto mid = (right + left) / 2;
            if (mid & 1) { // odd
                auto prev = mid - 1;
                if (nums[prev] == nums[mid])
                    left = mid + 1;
                else
                    right = mid;
            }
            else { // even
                auto next = mid + 1;
                if (nums[next] == nums[mid])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return nums[left];
    }
};

int main(void) {
    return 0;
}
