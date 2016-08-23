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
    TreeNode *ptr = nullptr;
    void inorderTraversal(TreeNode *root) {
        ptr->right = root;
        ptr->left = nullptr;
        ptr = ptr->right;
        auto right = root->right;
        if (root->left)
            inorderTraversal(root->left);
        if (right)
            inorderTraversal(right);
    }
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        ptr = root;
        auto right = root->right;
        if (root->left)
            inorderTraversal(root->left);
        if (right)
            inorderTraversal(right);
    }
};

int main(void) {
    // system("pause");
    return 0;
}
