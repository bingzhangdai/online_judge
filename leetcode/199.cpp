#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> bfs, next;
        vector<int> res;
        if (root)
            bfs.push(root);
        while (!bfs.empty()) {
            auto node = bfs.front();
            res.push_back(node->val);
            while (!bfs.empty()) {
                node = bfs.front();
                bfs.pop();
                if (node->right)
                    next.push(node->right);
                if (node->left)
                    next.push(node->left);
            }
            bfs.swap(next);
        }
        return res;
    }
};
int main(void) {
    return 0;
}
