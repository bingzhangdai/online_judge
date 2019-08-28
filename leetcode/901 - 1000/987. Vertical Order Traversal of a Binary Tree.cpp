#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int left = INT_MAX;
    int right = INT_MIN;
    unordered_map<int, vector<pair<int, int>>> hash_map;
    void inorder(TreeNode *root, int x, int y) {
        if (!root)
            return;
        left = min(left, x), right = max(right, x);
        hash_map[x].emplace_back(y, root->val);
        inorder(root->left, x - 1, y + 1);
        inorder(root->right, x + 1, y + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        inorder(root, 0, 0);
        vector<vector<int>> res;
        for (auto i = left; i <= right; i++) {
            res.push_back(vector<int>());
            sort(hash_map[i].begin(), hash_map[i].end());
            for (const auto& p : hash_map[i])
                res.back().push_back(p.second);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
