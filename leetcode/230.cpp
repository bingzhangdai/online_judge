#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    // return size
    int GetSizeAndKthSmallest(TreeNode *root, int k, int& res) {
        if (!root)
            return 0;
        int size = GetSizeAndKthSmallest(root->left, k, res);
        if (k <= size)
            return size;
        if (k == size + 1) {
            res = root->val;
            return size + 1;
        }
        return size + GetSizeAndKthSmallest(root->right, k - size - 1, res) + 1;
    }
public:
    int kthSmallest(TreeNode *root, int k) {
        int res;
        GetSizeAndKthSmallest(root, k, res);
        return res;
    }
};

int main(void) {
    return 0;
}
