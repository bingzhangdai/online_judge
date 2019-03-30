#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& res, int index, vector<int>& path) {
        if (target == 0)
            res.push_back(path);
        if (target <= 0)
            return;
        for (auto i = index; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], res, i, path);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates, target, res, 0, path);
        return res;
    }
};

int main(void) {
    vector<int> candidates = { 2,3,6,7 };
    cout << Solution().combinationSum(candidates, 7).size() << endl;
    system("pause");
    return 0;
}
