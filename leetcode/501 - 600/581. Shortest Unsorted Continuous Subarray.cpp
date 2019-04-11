#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        auto begin = -1, end = -2;
        int small = nums.back(), big = nums.front();
        for (int i = 0; i < nums.size(); i++) {
            big = max(big, nums[i]);
            if (big > nums[i])
                end = i;
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            small = min(small, nums[i]);
            if (small < nums[i])
                begin = i;
        }
        return end - begin + 1;
    }
};

int main(void) {
    return 0;
}
