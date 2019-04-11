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
    int res = 0;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int left = dfs(root->left), right = dfs(root->right);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode *root) {
        dfs(root);
        return res;
    }
};

int main(void) {
    return 0;
}
