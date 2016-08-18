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

// root->val == INT_MAX or INT_MIN, 太猥琐了
class Solution {
    bool check(TreeNode *root, long upper, long lower) {
        if (root == nullptr)
            return true;
        if (root->val < upper && root->val > lower)
            return check(root->left, root->val, lower) && check(root->right, upper, root->val);
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, (long)INT_MAX + 1, (long)INT_MIN - 1);
    }
};

int main(void) {
    cout << Solution().isValidBST(nullptr) << endl;
    // system("pause");
    return 0;
}

