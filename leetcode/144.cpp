#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> stk;
        if (root)
            stk.push(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            if (root->right)
                stk.push(root->right);
            if (root->left)
                stk.push(root->left);
            res.push_back(root->val);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
