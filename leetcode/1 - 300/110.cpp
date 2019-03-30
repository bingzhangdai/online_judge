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
    bool isbalance = true;
    int height(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        if (!isbalance)
            return 0;
        auto left = height(root->left);
        auto right = height(root->right);
        if (abs(left - right) > 1)
            isbalance = false;
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        height(root);
        return isbalance;
    }
};

int main(void) {
    // system("pause");
    return 0;
}
