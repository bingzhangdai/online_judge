#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        auto res = vector<vector<int>>();
        sort(nums.begin(), nums.end());
        for (auto i = 0; i < nums.size();) {
            // same as 3Sum
            for (auto j = i + 1; j < nums.size();) {
                for (int l = j + 1, m = nums.size() - 1; l < m;) {
                    auto sums = nums[i] + nums[j] + nums[l] + nums[m];
                    if (sums == target) {
                        res.push_back({ nums[i], nums[j], nums[l], nums[m] });
                    }
                    if (sums <= target) {
                        auto tmp = l + 1;
                        while (tmp < m && nums[tmp] == nums[l]) { tmp++; }
                        l = tmp;
                    }
                    else {
                        auto tmp = m - 1;
                        while (tmp > l && nums[tmp] == nums[m]) { tmp--; };
                        m = tmp;
                    }
                }
                auto tmp = j + 1;
                while (tmp < nums.size() && nums[tmp] == nums[j]) { tmp++; }
                j = tmp;
            }
            auto tmp = i + 1; 
            while (tmp < nums.size() && nums[tmp] == nums[i]) { tmp++; }
            i = tmp;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
