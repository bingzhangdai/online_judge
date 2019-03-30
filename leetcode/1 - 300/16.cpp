#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int i, j, k;
        int diff = INT_MAX;
        int res;
        sort(nums.begin(), nums.end());
        for (i = 0; i < nums.size();) {
            j = i + 1;
            k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < diff) {
                    res = sum;
                    diff = abs(sum - target);
                }
                if (sum - target >= 0) {
                    int m = k - 1;
                    while (m > j && nums[m] >= nums[k]) { m--; }
                    k = m;
                }
                else {
                    int m = j + 1;
                    while (m < k && nums[m] <= nums[j]) { m++; }
                    j = m;
                }
            }
            int m = i + 1;
            while (m < nums.size() && nums[m] == nums[i]) { m++; }
            i = m;
        }
        return res;
    }
};

int main(void) {
    cout << Solution().threeSumClosest(vector<int>({ -1, 2, 1, -4 }), 1) << endl;

    system("pause");
    return 0;
}
