#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void dfs(TreeNode *root, int sum, vector<vector<int>>& res, vector<int>& path) {
        if (!root) 
            return;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            if (sum == root->val)
                res.push_back(path);
        }
        if (root->left)
            dfs(root->left, sum - root->val, res, path);
        if (root->right)
            dfs(root->right, sum - root->val, res, path);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, sum, res, path);
        return res;
    }
};

int main(void) {
    // system("pause");
    return 0;
}
