#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int ind = nums.size() - 2;
        while (ind >= 0 && nums[ind] >= nums[ind + 1]) { ind--; }
        if (ind < 0) { 
            sort(nums.begin(), nums.end());
            return;
        }
        int ind2 = nums.size() - 1;
        while (ind2 > ind && nums[ind2] <= nums[ind]) { ind2--; }
        swap(nums[ind], nums[ind2]);
        sort(nums.begin() + ind + 1, nums.end());
        return;
    }
};

int main(void) {
    auto p = vector<int>({ 2,3,1 });
    Solution().nextPermutation(p);
    cout << p[0] << p[1] << p[2] << endl;
    return 0;
}
