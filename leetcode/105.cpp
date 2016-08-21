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
    TreeNode* build(vector<int>& preorder, int prel, int prer, vector<int>& inorder, int inl, int inr) {
        if (prel == prer)
            return nullptr;
        auto root = new TreeNode(preorder[prel]);
        auto mid = inl;
        while (inorder[mid++] != preorder[prel]);
        root->left = build(preorder, prel + 1, mid - inl + prel, inorder, inl, mid - 1);
        root->right = build(preorder, mid - inl + prel, prer, inorder, mid, inr);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};

int main(void) {
    // system("pause");
    return 0;
}
