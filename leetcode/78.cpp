#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& res, const vector<int>& nums, vector<int>& path, int pos) {
        res.push_back(path);
        for (int i = pos + 1; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(res, nums, path, i);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        auto res = vector<vector<int>>();
        auto path = vector<int>();
        dfs(res, nums, path, -1);
        return res;
    }
};


int main(void) {
    vector<int> nums{1,2,3};
    cout << Solution().subsets(nums).size() << endl;
    // system("pause");
    return 0;
}

