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
    int len = 0;
    int longestUnivaluePathWithValue(TreeNode *root, int value) {
        if (!root)
            return 0;
        if (root->val != value) {
            longestUnivaluePath(root);
            return 0;
        }
        int left_len = longestUnivaluePathWithValue(root->left, value),
            right_len = longestUnivaluePathWithValue(root->right, value);
        if (root->left && root->left->val == value && root->right && root->right->val == value)
            len = max(len, left_len + right_len);
        return max(left_len, right_len) + 1;
    }
public:
    int longestUnivaluePath(TreeNode *root) {
        if (!root)
            return 0;
        int left_len = longestUnivaluePathWithValue(root->left, root->val),
            right_len = longestUnivaluePathWithValue(root->right, root->val);
        if (root->left && root->left->val == root->val && root->right && root->right->val == root->val)
            len = max(len, left_len + right_len);
        len = max({ len, left_len, right_len });
        return len;
    }
};

int main(void) {
    return 0;
}
