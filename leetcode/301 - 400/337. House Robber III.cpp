#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int dfs(TreeNode *root, bool canRob) {
        if (!root)
            return 0;
        int res = dfs(root->left, true) + dfs(root->right, true);
        if (canRob) {
            int res2 = dfs(root->left, false) + dfs(root->right, false) + root->val;
            if (res2 > res)
                return res2;
        }
        return res;
    }
public:
    int rob(TreeNode *root) {
        return dfs(root, true);
    }
};

int main(void) {
    return 0;
}
