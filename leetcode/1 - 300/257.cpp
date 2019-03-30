#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void dfs(vector<string>& res, TreeNode *node, string path) {
        path += to_string(node->val);
        if (!node->left && !node->right) {
            res.push_back(path);
            return;
        }
        path += "->";
        if (node->left)
            dfs(res, node->left, path);
        if (node->right)
            dfs(res, node->right, path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr)
            return res;
        dfs(res, root, "");
        return res;
    }
};
int main(void) {
    return 0;
}
