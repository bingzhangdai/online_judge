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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p != nullptr && q != nullptr)
            return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isSameTree(root->left, root->right);
    }
};

int main(void) {
    cout << Solution().isSameTree(nullptr) << endl;
    // system("pause");
    return 0;
}

