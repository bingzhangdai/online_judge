#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
Input:
    2
   / \
  1   3
Output: true
Example 2:
    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool dfs(TreeNode *root, long lower, long upper) {
        if (root == nullptr)
            return true;
        if (root->val < upper && root->val > lower) {
            return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
        }
        return false;
    }
public:
    bool isValidBST(TreeNode *root) {
        return dfs(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }
};

int main(void) {
    cout << Solution().isValidBST(nullptr) << endl;

    return 0;
}

