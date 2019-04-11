#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int res = INT_MAX;
    void postOrder(TreeNode* root, int& min_val, int& max_val) {
        min_val = root->val, max_val = root->val;
        if (root->left) {
            int max_left;
            postOrder(root->left, min_val, max_left);
            res = min(res, root->val - max_left);
        }
        if (root->right) {
            int min_right;
            postOrder(root->right, min_right, max_val);
            res = min(res, min_right - root->val);
        }
    }
public:
    int getMinimumDifference(TreeNode * root) {
        if (!root)  return 0;
        int min_val, max_val;
        postOrder(root, min_val, max_val);
        return res;
    }
};

int main(void) {
    return 0;
}
