#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

// Zhaizhai taught me
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, i = 0;
        if (nums.size() == 1)
            return 0;
        while (i + nums[i] < nums.size() - 1) {
            int next = i + 1;
            for (int j = i + 2; j <= nums[i] + i; j++)
                if (nums[j] + j > next + nums[next])
                    next = j;
            i = next;
            jumps++;
        }
        return jumps + 1;
    }
};

// TLE T_T
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         auto jumps = vector<int>(nums.size(), INT_MAX);
//         jumps[0] = 0;
//         for (int i = 1; i < nums.size(); i++)
//             for (int j = 0; j < i; j++)
//                 if (j + nums[i] >= i)
//                     jumps[i] = min(jumps[i], jumps[j] + 1);
//         return jumps[nums.size() - 1];
//     }
// };

int main(void) {
    vector<int> nums = { 2,3,1,1,4 };
    cout << Solution().jump(nums) << endl;
    // system("pause");
    return 0;
}
