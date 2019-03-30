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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p != nullptr && q != nullptr)
            return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false;
    }
};

int main(void) {
    cout << Solution().isSameTree(nullptr, nullptr) << endl;
    // system("pause");
    return 0;
}

