#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (i != nums[i]) {
                if (nums[i] == n)
                    break;
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i = 0; i < n; i++)
            if (nums[i] != i)
                return i;
        return n;
    }
};

int main(void) {
    return 0;
}
