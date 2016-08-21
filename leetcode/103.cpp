#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        deque<TreeNode *> queue{};
        if (root != nullptr) {
            queue.push_back(root);
            queue.push_back(nullptr);
        }
        stack<int> stk;
        auto zigzag = false;
        while (queue.size()) {
            vector<int> level;
            auto flag = false;
            while (auto ptr = queue[0]) {
                queue.pop_front();
                if (zigzag)
                    stk.push(ptr->val);
                else
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
            if (zigzag)
                while (!stk.empty()) {
                    level.push_back(stk.top());
                    stk.pop();
                }
            zigzag = !zigzag;
            res.push_back(level);
        }
        return res;
    }
};

int main(void) {
    cout << Solution().zigzagLevelOrder(nullptr).size() << endl;
    // system("pause");
    return 0;
}
