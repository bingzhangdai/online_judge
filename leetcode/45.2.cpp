#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        auto steps = 0, pos = 0;
        while (pos < nums.size()) {
            if (pos == nums.size() - 1)
                break;
            auto jumps = pos + nums[pos], farest = 0, i = 0;
            for (i = pos; i < nums.size() && i <= jumps; i++) {
                auto tmp = i + nums[i];
                if (farest < tmp) {
                    farest = tmp;
                    pos = i;
                }
            }
            steps++;
        }
        return steps;
    }
};

int main(void) {
    vector<int> nums = { 2,3,1,1,4 };
    cout << Solution().jump(nums) << endl;
    // system("pause");
    return 0;
}
