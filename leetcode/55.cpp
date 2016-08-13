#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ind = 0;
        while (true) {
            int next = ind;
            for (int i = ind; i <= nums[ind] + ind; i++) {
                if (i >= nums.size() - 1)
                    return true;
                if (i + nums[i] >= next + nums[next])
                    next = i;
            }
            if (nums[ind] == 0)
                return false;
            ind = next;
        }
    }
};

int main(void) {
    vector<int> nums = { 3,2,1,0,4 };
    cout << Solution().canJump(nums) << endl;
    // system("pause");
    return 0;
}
