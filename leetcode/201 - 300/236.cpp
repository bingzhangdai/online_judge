#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<TreeNode *, int> hash_map;
    int inorderTraversal(TreeNode *root, int n) {
        if (!root)
            return n - 1;
        int left = inorderTraversal(root->left, n);
        hash_map[root] = left + 1;
        return inorderTraversal(root->right, left + 2);
    }
    TreeNode* lowestCommonAncestor235(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (hash_map[root] > hash_map[p] && hash_map[root] > hash_map[q])
            return lowestCommonAncestor235(root->left, p, q);
        if (hash_map[root] < hash_map[p] && hash_map[root] < hash_map[q])
            return lowestCommonAncestor235(root->right, p, q);
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        inorderTraversal(root, 0);
        return lowestCommonAncestor235(root, p, q);
    }
};

int main(void) {
    return 0;
}
