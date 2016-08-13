#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& res, vector<int>& path, int n, int pos, int k) {
        if (k == 0) {
            res.push_back(path);
            return;
        }
        for (int i = pos + 1; i < n; i++) {
            path.push_back(i + 1);
            dfs(res, path, n, i, k - 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        auto res = vector<vector<int>>();
        auto path = vector<int>();
        dfs(res, path, n, -1, k);
        return res;
    }
};


int main(void) {
    cout << Solution().combine(4, 2).size() << endl;
    // system("pause");
    return 0;
}

