#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *start;
        if (!root)
            return;
        for (start = root; start->left; start = start->left) {
            root = start;
            while (root) {
                root->left->next = root->right;
                if (root->next)
                    root->right->next = root->next->left;
                root = root->next;
            }
        }
    }
};
int main(void) {
    auto root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    Solution().connect(root);
    return 0;
}
