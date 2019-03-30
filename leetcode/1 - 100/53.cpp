#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int cursum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cursum < 0)
                cursum = 0;
            cursum += nums[i];
            if (cursum > maxsum)
                maxsum = cursum;
        }
        return maxsum;
    }
};

int main(void) {
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << Solution().maxSubArray(nums) << endl;
    // system("pause");
    return 0;
}
