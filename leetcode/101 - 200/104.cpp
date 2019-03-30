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
    int maxd = 0;
    void dfs(TreeNode *node, int depth) {
        if (node == nullptr) {
            maxd = max(maxd, depth);
            return;
        }
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
public:
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return maxd;
    }
};

int main(void) {
    cout << Solution().maxDepth(nullptr) << endl;
    // system("pause");
    return 0;
}
