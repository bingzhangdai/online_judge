#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> visited;
    vector<int> path;
    void dfs(vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size();) {
            if (visited[i] == 0) {
                visited[i] = 1;
                path.push_back(nums[i]);
                dfs(nums);
                path.pop_back();
                visited[i] = 0;
                int j = i;
                while (j < nums.size() && nums[j] == nums[i])
                    j++;
                i = j;
            }
            else
                i++;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        visited = vector<int>(nums.size(), 0);
        dfs(nums);
        return res;
    }
};

int main(void) {
    vector<int> nums = { 1,1,2 };
    cout << Solution().permuteUnique(nums).size() << endl;
    // system("pause");
    return 0;
}
