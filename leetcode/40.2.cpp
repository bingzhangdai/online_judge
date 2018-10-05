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
        
        for (auto i = index; i < candidates.size();) {
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], res, i + 1, path);
            int j = i + 1;
            while (j < candidates.size() && candidates[j] == candidates[i]) { j++; }
            i = j;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, res, 0, path);
        return res;
    }
};

int main(void) {
    vector<int> candidates = { 10,1,2,7,6,1,5 };
    cout << Solution().combinationSum2(candidates, 8).size() << endl;
    system("pause");
    return 0;
}
