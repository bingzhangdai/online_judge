#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root || L > R)
            return 0;
        auto res = rangeSumBST(root->left, L, min(root->val, R)) + rangeSumBST(root->right, max(root->val, L), R);
        if (root->val <= R && root->val >= L)
            res += root->val;
        return res;
    }
};

int main(void) {
    return 0;
}
