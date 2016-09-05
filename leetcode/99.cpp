#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *first = nullptr, *second = nullptr;
    TreeNode *inorder_tranversal(TreeNode *node, TreeNode *prev) {
        if (node->left)
            prev = inorder_tranversal(node->left, prev);
        if (node->val < (prev ? prev->val : INT_MIN)) {
            if (!first)
                first = prev;
            second = node;
        }
        if (node->right)
            return inorder_tranversal(node->right, node);
        return node;
    }
public:
    void recoverTree(TreeNode* root) {
        if (root == nullptr)
            return;
        inorder_tranversal(root, nullptr);
        if (first == nullptr)
            return;
        swap(first->val, second->val);
    }
};

int main(void) {
    return 0;
}

/*
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure. 
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
*/
