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
    bool istrue = false;
    void dfs(TreeNode *root, int sum) {
        if (root && !root->left && !root->right || istrue) {
            if (sum == root->val)
                istrue = true;
            return;
        }
        if (root && root->left)
            dfs(root->left, sum - root->val);
        if (root && root->right)
            dfs(root->right, sum - root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return istrue;
    }
};

int main(void) {
    // system("pause");
    return 0;
}
