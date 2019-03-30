#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& res, vector<int>& path, int num, int k, int n) {
        if (num * k > n)
            return;
        if (9 * k < n)
            return;
        if (n == 0 || k == 0) {
            if (n == 0 && k == 0)
                res.push_back(path);
            return;
        }
        for (int i = num; i <= 9; i++) {
            path.push_back(i);
            dfs(res, path, i + 1, k - 1, n - i);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, 1, k, n);
        return res;
    }
};

int main(void) {
    return 0;
}
