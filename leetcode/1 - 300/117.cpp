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
    TreeLinkNode *find_next_nonleaf_node(TreeLinkNode *root) {
        while (root && root->left == nullptr && root->right == nullptr)
            root = root->next;
        return root;
    }
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *start, *next;
        if (!root)
            return;
        for (start = root; start && (start->left || start->right); 
                start = find_next_nonleaf_node(start->left ? start->left : start->right)) {
            root = start;
            while (root) {
                next = find_next_nonleaf_node(root->next);
                if (root->left)
                    root->left->next = root->right ? root->right : next ? next->left ? next->left : next->right : nullptr;
                if (root->right)
                    root->right->next = next ? next->left ? next->left : next->right : nullptr;
                root = next;
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
