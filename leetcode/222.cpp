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
public:
    int countNodes(TreeNode* root) {
        int h = 0;
        auto left = root, right = root;
        while (right) {
            right = right->right;
            left = left->left;
            h++;
        }
        if (!left)
            return (1 << h) - 1;
        else
            return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main(void) {
    return 0;
}
