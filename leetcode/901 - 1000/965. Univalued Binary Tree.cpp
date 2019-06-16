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
    int val = -1;
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root)
            return true;
        if (val == -1)
            val = root->val;
        else if (val != root->val)
            return false;
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};

int main(void) {
    return 0;
}
