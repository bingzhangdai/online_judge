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
    TreeNode* build(vector<int>& inorder, int inl, int inr, vector<int>& postorder, int postl, int postr) {
        if (inl == inr)
            return nullptr;
        auto root = new TreeNode(postorder[postr - 1]);
        auto mid = inl;
        while (inorder[mid++] != postorder[postr - 1]);
        root->left = build(inorder, inl, mid - 1, postorder, postl, mid - inl - 1 + postl);
        root->right = build(inorder, mid, inr, postorder, mid - inl - 1 + postl, postr - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};

int main(void) {
    // system("pause");
    return 0;
}
