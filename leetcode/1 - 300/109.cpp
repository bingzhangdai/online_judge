#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
    TreeNode *sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(nums);
    }
};

int main(void) {
    // system("pause");
    return 0;
}

