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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode *, bool>> stk;
        vector<int> res;
        if (root)
            stk.push(make_pair(root, true));
        while (!stk.empty()) {
            auto node_pair = stk.top();
            root = node_pair.first;
            stk.pop();
            if (node_pair.second) {
                node_pair.second = false;
                stk.push(node_pair);
                if (root->right)
                    stk.push(make_pair(root->right, true));
                if (root->left)
                    stk.push(make_pair(root->left, true));
            }
            else
                res.push_back(root->val);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
