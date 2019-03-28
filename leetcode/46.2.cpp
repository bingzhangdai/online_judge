#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& path, vector<bool>& visited) {
        if (path.size() == nums.size()) {
            res.push_back(path);
        }
        for (auto i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                path.push_back(nums[i]);
                dfs(res, nums, path, visited);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        auto path = vector<int>(0);
        auto visited = vector<bool>(nums.size(), false);
        dfs(res, nums, path, visited);
        return res;
    }
};

int main(void) {
    vector<int> nums = { 1,2,3 };
    cout << Solution().permute(nums).size() << endl;
    // system("pause");
    return 0;
}
