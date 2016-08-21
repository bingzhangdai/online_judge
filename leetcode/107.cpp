#include <iostream>
#include <vector>
#include <deque>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        deque<TreeNode *> queue{};
        if (root != nullptr) {
            queue.push_back(root);
            queue.push_back(nullptr);
        }
        while (queue.size()) {
            vector<int> level;
            auto flag = false;
            while (auto ptr = queue[0]) {
                queue.pop_front();
                level.push_back(ptr->val);
                if (ptr->left) {
                    flag = true;
                    queue.push_back(ptr->left);
                }
                if (ptr->right) {
                    flag = true;
                    queue.push_back(ptr->right);
                }
            }
            queue.pop_front();
            if (flag)
                queue.push_back(nullptr);
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(void) {
    // system("pause");
    return 0;
}

