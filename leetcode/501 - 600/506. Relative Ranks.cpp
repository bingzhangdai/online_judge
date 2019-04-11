#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    string to_rank(int num) {
        if (num == 1)
            return "Gold Medal";
        if (num == 2)
            return "Silver Medal";
        if (num == 3)
            return "Bronze Medal";
        return to_string(num);
    }

public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int, int>> nums_new;
        for (int i = 0; i < nums.size(); i++) {
            nums_new.emplace_back(nums[i], i);
        }
        sort(nums_new.begin(), nums_new.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        vector<string> res(nums.size());
        for (int i = 0; i < nums_new.size(); i++) {
            res[nums_new[i].second] = to_rank(i + 1);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
