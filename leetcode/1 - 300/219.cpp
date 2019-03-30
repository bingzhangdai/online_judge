#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> hash_set;
        for (int i = 0, j = 0; i < n; i++) {
            if (i - j > k) {
                auto pos = hash_set.find(nums[j++]);
                if (pos != hash_set.end())
                    hash_set.erase(pos);
            }
            if (hash_set.find(nums[i]) != hash_set.end())
                return true;
            hash_set.insert(nums[i]);
        }
        return false;
    }
};

int main(void) {
    return 0;
}
