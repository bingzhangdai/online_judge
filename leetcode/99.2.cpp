#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure. 
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *first = nullptr, *second = nullptr;
    TreeNode *inOrder(TreeNode *root, TreeNode *prev) {
        if (root->left) {
            prev = inOrder(root->left, prev);
        }
        if (root->val < (prev ? prev->val : INT_MIN)) {
            if (!first)
                first = prev;
            second = root;
        }
        if (root->right)
            return inOrder(root->right, root);
        return root;
    }
public:
    void recoverTree(TreeNode *root) {
        inOrder(root, nullptr);
        swap(first->val, second->val);
    }
};

int main(void) {
    return 0;
}
