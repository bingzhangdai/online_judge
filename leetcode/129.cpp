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
    int sumNums = 0;
    void dfs(TreeNode *root, int sum) {
        int num = sum * 10 + root->val;
        if (!root->left && !root->right) {
            sumNums += num;
        }
        if (root->right)
            dfs(root->right, num);
        if (root->left)
            dfs(root->left, num);
    }
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr)
            return 0;
        dfs(root, 0);
        return sumNums;
    }
};

int main(void) {
    return 0;
}
