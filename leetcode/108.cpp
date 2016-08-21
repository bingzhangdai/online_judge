#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *build(vector<int>& nums, int left, int right) {
        if (left == right)
            return nullptr;
        auto mid = (left + right) / 2;
        auto root = new TreeNode(nums[mid]);
        root->left = build(nums, left, mid);
        root->right = build(nums, mid + 1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
};

int main(void) {
    // system("pause");
    return 0;
}

