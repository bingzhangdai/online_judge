#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int findNext(vector<int>& nums, int i) {
        for (auto j = i + 1; j < nums.size(); j++) {
            if (nums[j] != nums[i])
                return j;
        }
        return nums.size();
    }
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& path, vector<bool>& visited) {
        if (path.size() == nums.size()) {
            res.push_back(path);
        }
        for (auto i = 0; i < visited.size();) {
            if (!visited[i]) {
                visited[i] = true;
                path.push_back(nums[i]);
                dfs(res, nums, path, visited);
                path.pop_back();
                visited[i] = false;
                i = findNext(nums, i);
            }
            else {
                i++;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        auto path = vector<int>(0);
        auto visited = vector<bool>(nums.size(), false);
        dfs(res, nums, path, visited);
        return res;
    }
};

int main(void) {
    vector<int> nums = { 1,1,2 };
    cout << Solution().permuteUnique(nums).size() << endl;
    // system("pause");
    return 0;
}
