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
    int max_path_sum = INT_MIN;
    int maxSinglePathSum(TreeNode *root) {
        if (root == nullptr)
            return 0;
        auto left = maxSinglePathSum(root->left);
        auto right = maxSinglePathSum(root->right);
        max_path_sum = max(left + right + root->val, max_path_sum);
        auto single_path = max(left, right) + root->val;
        return (single_path < 0) ? 0 : single_path;
    }
public:
    int maxPathSum(TreeNode* root) {
        maxSinglePathSum(root);
        return max_path_sum;
    }
};

int main(void) {
    return 0;
}
