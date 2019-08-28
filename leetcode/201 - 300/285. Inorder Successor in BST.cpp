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
    bool found = false;
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (!root)
            return nullptr;
        auto left = inorderSuccessor(root->left, p);
        if (left)
            return left;
        if (found)
            return root;
        if (root == p)
            found = true;
        return inorderSuccessor(root->right, p);
    }
};

int main(void) {
    return 0;
}
