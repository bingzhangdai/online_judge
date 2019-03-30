#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, int target, vector<int>& path, int index) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (target < 0 || index == candidates.size())
            return;
        for (int i = index; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], path, i);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        auto path = vector<int>();
        dfs(candidates, target, path, 0);
        return res;
    }
};

int main(void) {
    vector<int> candidates = { 2,3,6,7 };
    cout << Solution().combinationSum(candidates, 7).size() << endl;
    system("pause");
    return 0;
}
