#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
    void dfs(vector<int>& path, vector<vector<int>>& res, const vector<int>& nums, int index) {
        res.push_back(path);
        while (index < nums.size()) {
            path.push_back(nums[index]);
            dfs(path, res, nums, index + 1);
            path.pop_back();
            index++;
            while (index < nums.size() && nums[index] == nums[index - 1])
                index++;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(path, res, nums, 0);
        return res;
    }
};

int main(void) {
    vector<int> nums {1,2,2};
    cout << Solution().subsetsWithDup(nums).size() << endl;
    // system("pause");
    return 0;
}
