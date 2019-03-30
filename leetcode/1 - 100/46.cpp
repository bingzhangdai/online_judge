#include <iostream>
#include <vector>
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
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                path.push_back(nums[i]);
                dfs(nums);
                path.pop_back();
                visited[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<int>(nums.size(), 0);
        dfs(nums);
        return res;
    }
};

int main(void) {
    vector<int> nums = { 1,2,3 };
    cout << Solution().permute(nums).size() << endl;
    // system("pause");
    return 0;
}
