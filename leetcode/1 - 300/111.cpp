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
    int mind = INT_MAX;
    void dfs(TreeNode *root, int depth) {
        if (!root->left && !root->right) {
            mind = min(mind, depth);
            return;
        }
        if (root->left)
            dfs(root->left, depth + 1);
        if (root->right)
            dfs(root->right, depth + 1);
    }
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        dfs(root, 1);
        return mind;
    }
};

int main(void) {
    // system("pause");
    return 0;
}
