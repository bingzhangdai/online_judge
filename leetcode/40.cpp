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
            dfs(candidates, target - candidates[i], path, i + 1);
            path.pop_back();
            int j = i;
            while (candidates[++j] == candidates[i]);
            // in for loop, i will become i + 1, that is, j
            // this line is ugly
            i = j - 1;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        auto path = vector<int>();
        dfs(candidates, target, path, 0);
        return res;
    }
};

int main(void) {
    vector<int> candidates = { 10,1,2,7,6,1,5 };
    cout << Solution().combinationSum2(candidates, 8).size() << endl;
    system("pause");
    return 0;
}
