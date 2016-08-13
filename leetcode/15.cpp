#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = vector<vector<int>>();
        int i, j, k;
        for (i = 0; i < nums.size();) {
            j = i + 1;
            // while (j < nums.size() && nums[j] == nums[i]) { j++; }
            k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                    res.push_back(vector<int>({ nums[i], nums[j], nums[k] }));
                if (sum >= 0) {
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
    cout << Solution().threeSum(vector<int>({ 0, 0, 0 }))[0][0] << endl;

    system("pause");
    return 0;
}
