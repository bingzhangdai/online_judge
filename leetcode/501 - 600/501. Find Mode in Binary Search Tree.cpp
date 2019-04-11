#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> res;
    int freq = 0;
    void inOrder(TreeNode *root, int& num, int& count) {
        if (!root)
            return;
        inOrder(root->left, num, count);
        if (root->val == num)
            count++;
        else if (root->val > num) {
            num = root->val;
            count = 1;
        }
        if (count > freq) {
            freq = count;
            res.clear();
            res.push_back(root->val);
        }
        else if (count == freq) {
            res.push_back(root->val);
        }
        cout << num << " " << count << endl;
        inOrder(root->right, num, count);
    }
public:
    vector<int> findMode(TreeNode *root) {
        int num = INT_MIN, count = 0;
        inOrder(root, num, count);
        return res;
    }
};

int main(void) {
    return 0;
}
