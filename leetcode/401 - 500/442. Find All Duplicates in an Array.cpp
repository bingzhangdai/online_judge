#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] != i + 1) {
                if (nums[i] == -1)
                    break;
                if (nums[i] == nums[nums[i] - 1]) {
                    res.push_back(nums[i]);
                    nums[i] = -1;
                    break;
                }
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return res;
    }
};

int main(void) {
    return 0;
}
